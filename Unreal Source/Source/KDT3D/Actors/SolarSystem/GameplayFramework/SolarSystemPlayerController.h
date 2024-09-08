// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/DataAsset.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "SolarSystemPlayerController.generated.h"


UCLASS()
class KDT3D_API USolarSystemPlayerControllerDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Input|InputMappingContext")
	UInputMappingContext* IMC = nullptr;

public:
	UPROPERTY(EditAnywhere, Category = "Input|InputAction")
	UInputAction* IA_Start = nullptr;

public:
	UPROPERTY(EditAnywhere, Category = "Loading")
	TSubclassOf<UUserWidget> LevelLodingWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Loading")
	TSoftObjectPtr<UWorld> NextLevel;
};

UCLASS()
class KDT3D_API ASolarSystemPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ASolarSystemPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

protected:
	void OnStart(const FInputActionValue& InputActionValue);

protected:
	UPROPERTY()
	class USolarSystemPlayerControllerDataAsset* SolarSystemPlayerControllerDataAsset;
};
