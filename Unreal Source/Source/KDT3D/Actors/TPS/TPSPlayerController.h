// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/PlayerController/BasicPlayerController.h"
#include "TPSPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class KDT3D_API ATPSPlayerController : public ABasicPlayerController
{
	GENERATED_BODY()

public:
	ATPSPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	void OnZoomIn(const FInputActionValue& InputActionValue);
	void OnZoomOut(const FInputActionValue& InputActionValue);

protected:
	class USoftWheelSpringArmComponent* SpringArm = nullptr;
	UInputMappingContext* IMC_TPS = nullptr;
};
