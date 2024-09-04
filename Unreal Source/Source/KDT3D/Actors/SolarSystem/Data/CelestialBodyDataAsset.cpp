// Fill out your copyright notice in the Description page of Project Settings.


#include "CelestialBodyDataAsset.h"

#if WITH_EDITOR
void UCelestialBodyDataAsset::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	bool bNotify = true;

	const FName PropertyName = PropertyChangedEvent.Property->GetFName();
	if (PropertyName == GET_MEMBER_NAME_CHECKED(ThisClass, bCalculateStarLightDirection))
	{
		if (bDynamicMaterialInstance == false && bCalculateStarLightDirection == true)
		{
			bCalculateStarLightDirection = false;
			UE_LOG(LogTemp, Warning, TEXT("bCalculateStarLightDirection를 사용하기 위해서는 bDynamicMaterialInstance가 true여야 합니다."));
			bNotify = false;
			ensure(false);
		}
	}

	if (bNotify)
	{
		OnCelestialBodyDataAssetChanged.Broadcast();
	}
}
#endif