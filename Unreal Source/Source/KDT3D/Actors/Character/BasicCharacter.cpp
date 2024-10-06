// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicCharacter.h"
#include "Components/NoFallCharacterMovementComponent.h"

UBasicCharacterDataAsset::UBasicCharacterDataAsset()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> ObjectFinder(TEXT("/Script/Engine.SkeletalMesh'/Game/Resources/ControlRig/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'"));
	check(ObjectFinder.Object);
	SkeletalMesh = ObjectFinder.Object;

	{
		const FRotator Rotation = FRotator(0., -90.0, 0.);
		const FVector Translation = FVector(0., 0., -90.0);
		SkeletalMeshTransform = FTransform(Rotation, Translation, FVector::OneVector);
	}
}

ABasicCharacter::ABasicCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UNoFallCharacterMovementComponent>(Super::CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USoftWheelSpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Weapon = CreateDefaultSubobject<UWeaponChildActorComponent>(TEXT("Weapon"));
	{
		SpringArm->SetupAttachment(GetMesh());
		SpringArm->ProbeSize = 5.0;
		SpringArm->bUsePawnControlRotation = true;
		SpringArm->bInheritRoll = false;
		SpringArm->SetMinMaxTargetArmLength(200.f, SpringArm->GetMaxTargetArmLength());
	}
	Camera->SetupAttachment(SpringArm);
	Weapon->SetupAttachment(GetMesh(), SocketName::Weapon);

	bUseControllerRotationYaw = false;

	//UCharacterMovementComponent* Movement = GetCharacterMovement();
	//Movement->bCanWalkOffLedges = false;
	const FRotator Rotation = FRotator(0., 90.0, 0.);
	const FVector Translation = FVector(0., 0., 90.0);
	FTransform SpringArmTransform = FTransform(Rotation, Translation, FVector::OneVector);
	SpringArm->SetRelativeTransform(SpringArmTransform);
}

// Called when the game starts or when spawned
void ABasicCharacter::BeginPlay()
{
	Super::BeginPlay();
	Weapon->GetChildActor()->SetOwner(this);
}

void ABasicCharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (LobbyCharacterDataAsset)
	{
		UpdateDataAsset();
	}
}

bool ABasicCharacter::CanJumpInternal_Implementation() const
{
	bool bJump = JumpIsAllowedInternal();
	if (!bJump && bIsCrouched)
	{
		bJump = true;
		auto& This = ConstCast(TObjectPtr<const ThisClass>(this));
		This->UnCrouch();
	}
	return bJump;
}

void ABasicCharacter::UpdateDataAsset()
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
	}
}

void ABasicCharacter::OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust)
{
	RecalculateBaseEyeHeight();
	FVector& MeshRelativeLocation = GetMesh()->GetRelativeLocation_DirectMutable();
	MeshRelativeLocation.Z = LobbyCharacterDataAsset->SkeletalMeshTransform.GetLocation().Z + HalfHeightAdjust;
	BaseTranslationOffset.Z = MeshRelativeLocation.Z;

	K2_OnStartCrouch(HalfHeightAdjust, ScaledHalfHeightAdjust);
}

void ABasicCharacter::OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust)
{
	RecalculateBaseEyeHeight();

	FVector& MeshRelativeLocation = GetMesh()->GetRelativeLocation_DirectMutable();
	MeshRelativeLocation.Z = LobbyCharacterDataAsset->SkeletalMeshTransform.GetLocation().Z;
	BaseTranslationOffset.Z = MeshRelativeLocation.Z;

	K2_OnEndCrouch(HalfHeightAdjust, ScaledHalfHeightAdjust);
}

// Called every frame
void ABasicCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABasicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

