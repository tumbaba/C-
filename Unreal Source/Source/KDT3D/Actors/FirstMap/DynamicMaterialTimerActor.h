// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/FirstMap/DynamicMaterialActor.h"
#include "DynamicMaterialTimerActor.generated.h"

/**
 * 
 */
UCLASS()
class KDT3D_API ADynamicMaterialTimerActor : public ADynamicMaterialActor
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

	UFUNCTION()
	void OnTimer();

private:
	int ColorIndex = 0;
	/*UPROPERTY()
	FTimerHandle TimerHandle;*/
};
