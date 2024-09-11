// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Animation/BaisicCharacterAnimInstance.h"
#include "LobbyCharacter.generated.h"


UCLASS()
class KDT3D_API ULobbyCharacterDataAsset : public UDataAsset
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
	UPROPERTY(EditAnywhere, Category = "SpringArm")
	FTransform SpringArmTransform;

public:
	ULobbyCharacterDataAsset();
};

UCLASS()
class KDT3D_API ALobbyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALobbyCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

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
	TObjectPtr<USpringArmComponent> SpringArm;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UCameraComponent> Camera;

protected:
	UPROPERTY(EditAnywhere)
	ULobbyCharacterDataAsset* LobbyCharacterDataAsset;
};
