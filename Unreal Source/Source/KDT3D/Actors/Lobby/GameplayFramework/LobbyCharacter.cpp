// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Lobby/GameplayFramework/LobbyCharacter.h"
#include "Components/NoFallCharacterMovementComponent.h"

ULobbyCharacterDataAsset::ULobbyCharacterDataAsset()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> ObjectFinder(TEXT("/Script/Engine.SkeletalMesh'/Game/Resources/ControlRig/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'"));
	check(ObjectFinder.Object);
	SkeletalMesh = ObjectFinder.Object;

	{
		const FRotator Rotation = FRotator(0., -90.0, 0.);
		const FVector Translation = FVector(0., 0., -90.0);
		SkeletalMeshTransform = FTransform(Rotation, Translation, FVector::OneVector);
	}
	{
		const FRotator Rotation = FRotator(0., 90.0, 0.);
		const FVector Translation = FVector(0., 0., 90.0);
		SpringArmTransform = FTransform(Rotation, Translation, FVector::OneVector);
	}
}

ALobbyCharacter::ALobbyCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UNoFallCharacterMovementComponent>(Super::CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	{
		SpringArm->SetupAttachment(GetMesh());
		SpringArm->ProbeSize = 5.0;
		SpringArm->bUsePawnControlRotation = true;
		SpringArm->bInheritRoll = false;
	}
	Camera->SetupAttachment(SpringArm);

	bUseControllerRotationYaw = false;

	//UCharacterMovementComponent* Movement = GetCharacterMovement();
	//Movement->bCanWalkOffLedges = false;
}

// Called when the game starts or when spawned
void ALobbyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALobbyCharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (LobbyCharacterDataAsset)
	{
		UpdateDataAsset();
	}
}

void ALobbyCharacter::UpdateDataAsset()
{
	if (!LobbyCharacterDataAsset) { return; }

	{
		UCharacterMovementComponent* Movement = GetCharacterMovement();
		Movement->RotationRate = LobbyCharacterDataAsset->RotationRate;
		Movement->bOrientRotationToMovement = LobbyCharacterDataAsset->bOrientRotationToMovement;
		Movement->GetNavAgentPropertiesRef().bCanCrouch = LobbyCharacterDataAsset->bCanCrouch;

		const float NewCapsuleHalfHeight = LobbyCharacterDataAsset->CapsuleHalfHeight * 0.5f;
		Movement->SetCrouchedHalfHeight(NewCapsuleHalfHeight);
	}
	{
		UCapsuleComponent* Capsule = GetCapsuleComponent();
		if (!FMath::IsNearlyEqual(Capsule->GetUnscaledCapsuleHalfHeight(), LobbyCharacterDataAsset->CapsuleHalfHeight))
		{
			Capsule->SetCapsuleHalfHeight(LobbyCharacterDataAsset->CapsuleHalfHeight, false);
		}
	}
	{
		USkeletalMeshComponent* SkeletalMeshComponent = GetMesh();
		SkeletalMeshComponent->SetSkeletalMesh(LobbyCharacterDataAsset->SkeletalMesh);
		SkeletalMeshComponent->SetRelativeTransform(LobbyCharacterDataAsset->SkeletalMeshTransform);
		SkeletalMeshComponent->SetAnimClass(LobbyCharacterDataAsset->AnimClass);

		SpringArm->SetRelativeTransform(LobbyCharacterDataAsset->SpringArmTransform);
	}
}

void ALobbyCharacter::OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust)
{
	RecalculateBaseEyeHeight();
	FVector& MeshRelativeLocation = GetMesh()->GetRelativeLocation_DirectMutable();
	MeshRelativeLocation.Z = LobbyCharacterDataAsset->SkeletalMeshTransform.GetLocation().Z + HalfHeightAdjust;
	BaseTranslationOffset.Z = MeshRelativeLocation.Z;

	K2_OnStartCrouch(HalfHeightAdjust, ScaledHalfHeightAdjust);
}

void ALobbyCharacter::OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust)
{
	RecalculateBaseEyeHeight();

	FVector& MeshRelativeLocation = GetMesh()->GetRelativeLocation_DirectMutable();
	MeshRelativeLocation.Z = LobbyCharacterDataAsset->SkeletalMeshTransform.GetLocation().Z;
	BaseTranslationOffset.Z = MeshRelativeLocation.Z;

	K2_OnEndCrouch(HalfHeightAdjust, ScaledHalfHeightAdjust);
}

// Called every frame
void ALobbyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetMovementComponent()->IsFalling())
	{
		
	}
}

// Called to bind functionality to input
void ALobbyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

