// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FirstMap/DynamicMaterialTimerActor.h"
#include "Kismet/KismetSystemLibrary.h"

void ADynamicMaterialTimerActor::BeginPlay()
{
	Super::BeginPlay();

	/*auto TimerDelegate = [this]()
		{
			static FLinearColor ColorTalbe[3] = { FLinearColor::Red, FLinearColor::Green, FLinearColor::Blue };

			MID->SetVectorParameterValue(TEXT("BaseColor"), ColorTalbe[ColorIndex]);
			ColorIndex = ColorIndex + 1;
			ColorIndex = ColorIndex % 3;
		};

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, 0.1f, true);*/
	UKismetSystemLibrary::K2_SetTimer(this, TEXT("OnTimer"), 0.1f, true);
}

void ADynamicMaterialTimerActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	/*GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);*/
}

void ADynamicMaterialTimerActor::OnTimer()
{
	static FLinearColor ColorTalbe[3] = { FLinearColor::Red, FLinearColor::Green, FLinearColor::Blue };

	MID->SetVectorParameterValue(TEXT("BaseColor"), ColorTalbe[ColorIndex]);
	ColorIndex = ColorIndex + 1;
	ColorIndex = ColorIndex % 3;
}
