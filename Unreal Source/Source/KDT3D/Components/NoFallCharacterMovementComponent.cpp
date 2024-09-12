// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/NoFallCharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "AI/Navigation/NavigationDataInterface.h"

UNoFallCharacterMovementComponent::UNoFallCharacterMovementComponent()
{
	SetMovementMode(EMovementMode::MOVE_NavWalking);
	bCanWalkOffLedges = true;
}

void UNoFallCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	SetMovementMode(EMovementMode::MOVE_NavWalking);
	bCanWalkOffLedges = true;
}

void UNoFallCharacterMovementComponent::StartNewPhysics(float deltaTime, int32 Iterations)
{
	if (MovementMode == MOVE_Falling && LastMovementMode != MovementMode)
	{
		StartFallingFowardDirction = GetOwner()->GetActorForwardVector();
		StartFallingRightDirction = GetOwner()->GetActorRightVector();
	}

	LastMovementMode = MovementMode;

	Super::StartNewPhysics(deltaTime, Iterations);
}

void UNoFallCharacterMovementComponent::PhysFalling(float deltaTime, int32 Iterations)
{
	if (IsCliff(StartFallingFowardDirction) || IsCliff(StartFallingRightDirction) || IsCliff(-StartFallingRightDirction))
	{
		Velocity.X = 0;
		Velocity.Y = 0;
		Acceleration.X = 0;
		Acceleration.Y = 0;
	}

	Super::PhysFalling(deltaTime, Iterations);
}

bool UNoFallCharacterMovementComponent::FindNavFloorCustomSearchRadius(const FVector& TestLocation, FNavLocation& NavFloorLocation, const float CustomSearchRadius) const
{
	const INavigationDataInterface* NavData = GetNavData();
	if (NavData == nullptr || CharacterOwner == nullptr)
	{
		return false;
	}

	const FNavAgentProperties& AgentProps = CharacterOwner->GetNavAgentPropertiesRef();
	const float SearchRadius = CustomSearchRadius;
	const float SearchHeight = AgentProps.AgentHeight * AgentProps.NavWalkingSearchHeightScale;

	return NavData->ProjectPoint(TestLocation, NavFloorLocation, FVector(SearchRadius, SearchRadius, SearchHeight));
}

void UNoFallCharacterMovementComponent::PhysNavWalking(float deltaTime, int32 Iterations)
{
	//SCOPE_CYCLE_COUNTER(STAT_CharPhysNavWalking);

	if (deltaTime < MIN_TICK_TIME)
	{
		return;
	}

	if ((!CharacterOwner || !CharacterOwner->Controller) && !bRunPhysicsWithNoController && !HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity())
	{
		Acceleration = FVector::ZeroVector;
		Velocity = FVector::ZeroVector;
		return;
	}

	if (UpdatedPrimitive)
	{
		UpdatedPrimitive->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
		UpdatedPrimitive->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	}

	const EMovementMode StartingMovementMode = MovementMode;
	const uint8 StartingCustomMovementMode = CustomMovementMode;

	RestorePreAdditiveRootMotionVelocity();

	// Ensure velocity is horizontal.
	MaintainHorizontalGroundVelocity();
	//devCode(ensureMsgf(!Velocity.ContainsNaN(), TEXT("PhysNavWalking: Velocity contains NaN before CalcVelocity (%s)\n%s"), *GetPathNameSafe(this), *Velocity.ToString()));

	//bound acceleration
	Acceleration.Z = 0.f;
	if (!HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity())
	{
		CalcVelocity(deltaTime, GroundFriction, false, GetMaxBrakingDeceleration());
		//devCode(ensureMsgf(!Velocity.ContainsNaN(), TEXT("PhysNavWalking: Velocity contains NaN after CalcVelocity (%s)\n%s"), *GetPathNameSafe(this), *Velocity.ToString()));
	}

	ApplyRootMotionToVelocity(deltaTime);

	if (MovementMode != StartingMovementMode || CustomMovementMode != StartingCustomMovementMode)
	{
		// Root motion could have taken us out of our current mode
		StartNewPhysics(deltaTime, Iterations);
		return;
	}

	Iterations++;

	FVector DesiredMove = Velocity;
	DesiredMove.Z = 0.f;

	const FVector OldLocation = GetActorFeetLocation();
	const FVector DeltaMove = DesiredMove * deltaTime;
	const bool bDeltaMoveNearlyZero = DeltaMove.IsNearlyZero();

	FVector AdjustedDest = OldLocation + DeltaMove;
	FNavLocation DestNavLocation;

	bool bSameNavLocation = false;
	if (CachedNavLocation.NodeRef != INVALID_NAVNODEREF)
	{
		if (bProjectNavMeshWalking)
		{
			const float DistSq2D = (OldLocation - CachedNavLocation.Location).SizeSquared2D();
			const float DistZ = FMath::Abs(OldLocation.Z - CachedNavLocation.Location.Z);

			const float TotalCapsuleHeight = CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight() * 2.0f;
			const float ProjectionScale = (OldLocation.Z > CachedNavLocation.Location.Z) ? NavMeshProjectionHeightScaleUp : NavMeshProjectionHeightScaleDown;
			const float DistZThr = TotalCapsuleHeight * FMath::Max(0.f, ProjectionScale);

			bSameNavLocation = (DistSq2D <= UE_KINDA_SMALL_NUMBER) && (DistZ < DistZThr);
		}
		else
		{
			bSameNavLocation = CachedNavLocation.Location.Equals(OldLocation);
		}

		if (bDeltaMoveNearlyZero && bSameNavLocation)
		{
			if (const INavigationDataInterface* NavData = GetNavData())
			{
				if (!NavData->IsNodeRefValid(CachedNavLocation.NodeRef))
				{
					CachedNavLocation.NodeRef = INVALID_NAVNODEREF;
					bSameNavLocation = false;
				}
			}
		}
	}

	if (bDeltaMoveNearlyZero && bSameNavLocation)
	{
		DestNavLocation = CachedNavLocation;
		UE_LOG(LogTemp, VeryVerbose, TEXT("%s using cached navmesh location! (bProjectNavMeshWalking = %d)"), *GetNameSafe(CharacterOwner), bProjectNavMeshWalking);
	}
	else
	{
		//SCOPE_CYCLE_COUNTER(STAT_CharNavProjectPoint);

		// Start the trace from the Z location of the last valid trace.
		// Otherwise if we are projecting our location to the underlying geometry and it's far above or below the navmesh,
		// we'll follow that geometry's plane out of range of valid navigation.
		if (bSameNavLocation && bProjectNavMeshWalking)
		{
			AdjustedDest.Z = CachedNavLocation.Location.Z;
		}

		// Find the point on the NavMesh
		const bool bHasNavigationData = FindNavFloorCustomSearchRadius(AdjustedDest, DestNavLocation, 0);
		if (!bHasNavigationData)
		{
			SetMovementMode(MOVE_Walking);
			return;
		}

		CachedNavLocation = DestNavLocation;
	}

	if (DestNavLocation.NodeRef != INVALID_NAVNODEREF)
	{
		FVector NewLocation(AdjustedDest.X, AdjustedDest.Y, DestNavLocation.Location.Z);
		if (bProjectNavMeshWalking)
		{
			//SCOPE_CYCLE_COUNTER(STAT_CharNavProjectLocation);
			const float TotalCapsuleHeight = CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight() * 2.0f;
			const float UpOffset = TotalCapsuleHeight * FMath::Max(0.f, NavMeshProjectionHeightScaleUp);
			const float DownOffset = TotalCapsuleHeight * FMath::Max(0.f, NavMeshProjectionHeightScaleDown);
			NewLocation = ProjectLocationFromNavMesh(deltaTime, OldLocation, NewLocation, UpOffset, DownOffset);
		}

		FVector AdjustedDelta = NewLocation - OldLocation;

		if (!AdjustedDelta.IsNearlyZero())
		{
			FHitResult HitResult;
			SafeMoveUpdatedComponent(AdjustedDelta, UpdatedComponent->GetComponentQuat(), bSweepWhileNavWalking, HitResult);
		}

		// Update velocity to reflect actual move
		if (!bJustTeleported && !HasAnimRootMotion() && !CurrentRootMotion.HasVelocity())
		{
			Velocity = (GetActorFeetLocation() - OldLocation) / deltaTime;
			MaintainHorizontalGroundVelocity();
		}

		bJustTeleported = false;
	}
	else
	{
		StartFalling(Iterations, deltaTime, deltaTime, DeltaMove, OldLocation);
	}
}

struct FScopedCapsuleMovementUpdate : public FScopedMovementUpdate
{
	typedef FScopedMovementUpdate Super;

	FScopedCapsuleMovementUpdate(USceneComponent* UpdatedComponent, bool bEnabled)
		: Super(bEnabled ? UpdatedComponent : nullptr, EScopedUpdate::DeferredUpdates)
	{
	}
};

void UNoFallCharacterMovementComponent::PhysWalking(float deltaTime, int32 Iterations)
{
	FScopedCapsuleMovementUpdate ScopedStepUpMovement(UpdatedComponent, true);

	Super::PhysWalking(deltaTime, Iterations);
	
	if (MovementMode == EMovementMode::MOVE_Walking)
	{
		// Walking 상태 일 때 Nav 바닥을 찾으면 NavWalking으로 전환 한다
		// 이미 Crouching 중이라면 전환을 미룬다
		if (FNavLocation NavFloorLocation; !IsCrouching() && FindNavFloorCustomSearchRadius(GetActorFeetLocation(), NavFloorLocation, 0.f))
		{
			SetMovementMode(MOVE_NavWalking);
		}
		else
		{
			// 일반 걷기 중일 때 절벽이 있으면 이동을 취소한다
			const FVector FowardDirection = GetOwner()->GetActorForwardVector();
			const FVector RightDirection = GetOwner()->GetActorRightVector();
			if (IsCliff(FowardDirection) || IsCliff(RightDirection) || IsCliff(-RightDirection))
			{
				ScopedStepUpMovement.RevertMove();
				return;
			}
		}
	}
}

bool UNoFallCharacterMovementComponent::IsCliff(const FVector& Direction)
{
	ACharacter* Character = Cast<ACharacter>(GetOwner());

	FHitResult HitResult;
	FCollisionQueryParams Params;
	const FNavAgentProperties& AgentProps = CharacterOwner->GetNavAgentPropertiesRef();
	const float SearchRadius = AgentProps.AgentRadius * 2.0f;
	const FVector Start = GetActorLocation() + Direction * SearchRadius;
	const FVector End = Start - FVector(0, 0, 1000.0);
	Params.AddIgnoredActor(Character);
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params);

	// DrawDebugLine
	{
		FColor LineColor = FColor::Red;
		FColor NavLineColor = FColor::Cyan;
		if (!bHit)
		{
			LineColor = FColor::Green;
		}
		DrawDebugLine(GetWorld(), Start, End, LineColor, false, 3.f, 0U, 2.f);
	}

	return !bHit;
}
