// Fill out your copyright notice in the Description page of Project Settings.


#include "LoadingScreen/AsyncLoadingScreenSubsystem.h"
#include "Blueprint/UserWidget.h"
#include "MoviePlayer.h"
#include "Kismet/GameplayStatics.h"

void UAsyncLoadingScreenSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UAsyncLoadingScreenSubsystem::OpenLevelWithLoadingScreen(TSubclassOf<UUserWidget> WidgetClass, const TSoftObjectPtr<UWorld> Level)
{
	if (!WidgetClass)
	{
		ensureMsgf(false, TEXT("WidgetClass is nullptr"));
		return;
	}
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);

	if (IsMoviePlayerEnabled())
	{
		FLoadingScreenAttributes LoadingScreenAttributes;
		LoadingScreenAttributes.WidgetLoadingScreen = Widget->TakeWidget();
		//LoadingScreenAttributes.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();
		LoadingScreenAttributes.MinimumLoadingScreenDisplayTime = 3.f;
		LoadingScreenAttributes.bAutoCompleteWhenLoadingCompletes = true;
		LoadingScreenAttributes.bAllowEngineTick = true;

		GetMoviePlayer()->SetupLoadingScreen(LoadingScreenAttributes);
	}

	UGameplayStatics::OpenLevelBySoftObjectPtr(this, Level);
}
