// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SolarSystem/Star.h"
#include "Data/StarDataAsset.h"

AStar::AStar()
{
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	PointLight->SetupAttachment(Body);
	PointLight->Intensity = 10.f;
	PointLight->bUseInverseSquaredFalloff = false;
	StarEmissivePowerTimelineComponent = CreateDefaultSubobject<UTimelineComponent>(TEXT("StarEmissivePowerTimelineComponent"));

	StarEmissivePowerTimelineComponent->SetLooping(true);
}

void AStar::UpdateDataAsset()
{
	Super::UpdateDataAsset();

	StarBodyData = Cast<UStarDataAsset>(CelestialBodyData);
	if (!StarBodyData) { return; }

	PointLight->Intensity = StarBodyData->LightIntensity;
	PointLight->AttenuationRadius = StarBodyData->LightAttenuationRadius;
	PointLight->LightFalloffExponent = StarBodyData->LightFalloffExponent;

	if (StarBodyData->StarEmissivePowerCurve)
	{
		TSet<UCurveBase*> Curves;
		StarEmissivePowerTimelineComponent->GetAllCurves(Curves);
		if (Curves.IsEmpty())
		{
			FOnTimelineFloat Delegate;
			Delegate.BindUFunction(this, TEXT("OnStarPower"));
			StarEmissivePowerTimelineComponent->AddInterpFloat(StarBodyData->StarEmissivePowerCurve, Delegate, NAME_None, TrackName);
		}
		else
		{
			StarEmissivePowerTimelineComponent->SetFloatCurve(StarBodyData->StarEmissivePowerCurve, TrackName);
		}
	}

	StarEmissivePowerTimelineComponent->SetPlayRate(StarBodyData->PlayRate);
#if WITH_EDITOR
	OnStarDataAssetChanged.Broadcast();
#endif
}

void AStar::BeginPlay()
{
	Super::BeginPlay();

	if (StarBodyData && StarBodyData->StarEmissivePowerCurve)
	{
		StarEmissivePowerTimelineComponent->Play();
	}
}

void AStar::OnStarPower(float Value)
{
	BodyMID->SetScalarParameterValue(MID_EmissivePower, Value);
}
