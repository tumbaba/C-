// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/SolarSystem/Data/CelestialBodyDataAsset.h"
#include "StarDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class KDT3D_API UStarDataAsset : public UCelestialBodyDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Star")
	UCurveFloat* StarEmissivePowerCurve = nullptr;

	UPROPERTY(EditAnywhere, Category = "Star")
	float PlayRate = 1.f;
};
