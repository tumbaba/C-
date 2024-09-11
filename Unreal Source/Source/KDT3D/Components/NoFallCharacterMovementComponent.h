// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NoFallCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class KDT3D_API UNoFallCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
public:
	UNoFallCharacterMovementComponent();

public:
	virtual void BeginPlay() override;

	virtual void StartNewPhysics(float deltaTime, int32 Iterations) override;

	virtual void PhysFalling(float deltaTime, int32 Iterations) override;

	virtual bool FindNavFloorCustomSearchRadius(const FVector& TestLocation, FNavLocation& NavFloorLocation, const float CustomSearchRadius) const;
	virtual void PhysNavWalking(float deltaTime, int32 Iterations) override;

	virtual void PhysWalking(float deltaTime, int32 Iterations) override;

protected:
	bool IsCliff(const FVector& Direction);

protected:
	FVector StartFallingForwardDirction;
	FVector StartFallingRightDirction;
	TEnumAsByte<enum EMovementMode> LastMovementMode;
};
