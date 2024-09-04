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
	UStarDataAsset() { bDynamicMaterialInstance = true; }

	UPROPERTY(EditAnywhere, Category = "Star")
	UCurveFloat* StarEmissivePowerCurve = nullptr;

	UPROPERTY(EditAnywhere, Category = "Star")
	float PlayRate = 1.f;

	UPROPERTY(EditAnywhere, Category = "Star|Light", meta = (UIMin = "8.0", UIMax = "16384.0"))
	float LightAttenuationRadius = 1000.f;
	UPROPERTY(EditAnywhere, Category = "Star|Light", meta = (UIMin = "0.0", UIMax = "20.0"))
	float LightIntensity = 10.f;
	UPROPERTY(EditAnywhere, Category = "Star|Light", meta = (UIMin = "0.1", UIMax = "16.0"))
	float LightFalloffExponent = 8.f;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};
