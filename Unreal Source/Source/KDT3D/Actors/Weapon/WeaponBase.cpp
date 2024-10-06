// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Weapon/WeaponBase.h"

FWeaponTableRow::FWeaponTableRow()
	: WeaponClass(AWeaponBase::StaticClass())
{
}

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	SkeletalMeshComponent->SetupAttachment(RootComponent);
	SkeletalMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Input
	{
		static ConstructorHelpers::FObjectFinder<UInputMappingContext> Asset
		{ TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Blueprint/Weapon/Input/IMC_Weapon.IMC_Weapon'") };
		check(Asset.Object);

		IMC_Weapon = Asset.Object;
	}
}

void AWeaponBase::SetData(const FDataTableRowHandle& InDataTableRowHandle)
{
	DataTableRowHandle = InDataTableRowHandle;
	if (DataTableRowHandle.IsNull()) { return; }
	FWeaponTableRow* Data = DataTableRowHandle.GetRow<FWeaponTableRow>(TEXT("Weapon"));
	if (!Data) { ensure(false); return; }
	WeaponTableRow = Data;

	SkeletalMeshComponent->SetSkeletalMesh(Data->SkeletalMesh);
	SkeletalMeshComponent->SetRelativeTransform(Data->Transform);
	check(Data->AnimClass);
	USkeletalMeshComponent* MeshComponent = GetOwner()->GetComponentByClass<USkeletalMeshComponent>();
	check(MeshComponent);
	MeshComponent->SetAnimClass(Data->AnimClass);

	// Owner 정보 세팅
	{
		OwningPawn = Cast<APawn>(GetOwner());
		check(OwningPawn);
		OwningPawnBodyMesh = OwningPawn->GetComponentByClass<USkeletalMeshComponent>();
		check(OwningPawnBodyMesh);
		BasicAnimInstance = Cast<UBaisicCharacterAnimInstance>(MeshComponent->GetAnimInstance());
		check(BasicAnimInstance);
	}

	// Input
	{
		if (APlayerController* PC = Cast<APlayerController>(OwningPawn->GetController()))
		{
			UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());
			if (!Subsystem->HasMappingContext(IMC_Weapon))
			{
				Subsystem->AddMappingContext(IMC_Weapon, 0);
			}

			if (!InputComponent)
			{
				EnableInput(PC);
				UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
				ensure(EnhancedInputComponent);
				if (const UInputAction* InputAction = FUtils::GetInputActionFromName(IMC_Weapon, TEXT("IA_Fire")))
				{
					EnhancedInputComponent->BindAction(InputAction, ETriggerEvent::Triggered, this, &ThisClass::OnFire);
				}
			}
		}
	}
}

void AWeaponBase::OnFire(const FInputActionValue& InputActionValue)
{
	if (WeaponTableRow->WeaponAttackMontage)
	{
		// 모든 몽타주가 재생 중이지 않을 때
		if (!BasicAnimInstance->Montage_IsPlaying(nullptr))
		{
			BasicAnimInstance->Montage_Play(WeaponTableRow->WeaponAttackMontage);
		}
	}
}

void AWeaponBase::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	SetData(DataTableRowHandle);
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}