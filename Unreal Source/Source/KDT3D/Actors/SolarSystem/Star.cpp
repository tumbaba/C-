// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SolarSystem/Star.h"
#include "Data/StarDataAsset.h"

AStar::AStar()
{
	StarEmissivePowerTimelineComponent = CreateDefaultSubobject<UTimelineComponent>(TEXT("StarEmissivePowerTimelineComponent"));

	StarEmissivePowerTimelineComponent->SetLooping(true);
}

void AStar::UpdateDataAsset()
{
	Super::UpdateDataAsset();

	StarBodyData = Cast<UStarDataAsset>(CelestialBodyData);
	if (!StarBodyData) { return; }

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

	MID = Body->CreateDynamicMaterialInstance(0);
}

void AStar::BeginPlay()
{
	Super::BeginPlay();

	if (StarBodyData->StarEmissivePowerCurve)
	{
		StarEmissivePowerTimelineComponent->Play();
	}
}

void AStar::OnStarPower(float Value)
{
	MID->SetScalarParameterValue(MID_EmissivePower, Value);
}
