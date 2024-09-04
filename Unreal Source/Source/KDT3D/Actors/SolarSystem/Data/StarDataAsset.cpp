// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SolarSystem/Data/StarDataAsset.h"

#if WITH_EDITOR
void UStarDataAsset::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	const FName PropertyName = PropertyChangedEvent.Property->GetFName();
	if (PropertyName == GET_MEMBER_NAME_CHECKED(ThisClass, bDynamicMaterialInstance))
	{
		if (bDynamicMaterialInstance == false)
		{
			bDynamicMaterialInstance = true;
			UE_LOG(LogTemp, Warning, TEXT("StarDataAsset은 bDynamicMaterialInstance가 무조건 true여야 합니다."));
			ensure(false);
		}
	}
	else if (PropertyName == GET_MEMBER_NAME_CHECKED(ThisClass, bCalculateStarLightDirection))
	{
		if (bCalculateStarLightDirection == true)
		{
			bCalculateStarLightDirection = false;
			UE_LOG(LogTemp, Warning, TEXT("Star와 bCalculateStarLightDirection는 호환되지 않는 옵션입니다."));
			ensure(false);
		}
	}
}
#endif