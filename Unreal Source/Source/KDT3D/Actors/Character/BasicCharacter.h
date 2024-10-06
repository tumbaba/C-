// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SoftWheelSpringArmComponent.h"
#include "Components/WeaponChildActorComponent.h"
#include "Animation/BaisicCharacterAnimInstance.h"
#include "Misc/Utils.h"
#include "Actors/Weapon/WeaponBase.h"
#include "BasicCharacter.generated.h"


UCLASS()
class KDT3D_API UBasicCharacterDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "MovementComponent")
	FRotator RotationRate = FRotator(0.0, 720.0, 0.0);
	UPROPERTY(EditAnywhere, Category = "MovementComponent")
	bool bOrientRotationToMovement = true;
	UPROPERTY(EditAnywhere, Category = "MovementComponent|Crouch")
	bool bCanCrouch = true;

public:
	UPROPERTY(EditAnywhere, Category = "CapsuleComponent")
	float CapsuleHalfHeight = 90.f;

public:
	UPROPERTY(EditAnywhere, Category = "SkeletalMeshComponent")
	USkeletalMesh* SkeletalMesh = nullptr;

	UPROPERTY(EditAnywhere, Category = "SkeletalMeshComponent")
	TSubclassOf<UBaisicCharacterAnimInstance> AnimClass = UBaisicCharacterAnimInstance::StaticClass();

	UPROPERTY(EditAnywhere, Category = "SkeletalMeshComponent")
	FTransform SkeletalMeshTransform;

public:
	UBasicCharacterDataAsset();
};

UCLASS()
class KDT3D_API ABasicCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasicCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual bool CanJumpInternal_Implementation() const override;

protected:
	virtual void UpdateDataAsset();

protected:
	virtual void OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust);
	virtual void OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<USoftWheelSpringArmComponent> SpringArm;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UWeaponChildActorComponent> Weapon;

protected:
	UPROPERTY(EditAnywhere)
	UBasicCharacterDataAsset* LobbyCharacterDataAsset;
};
