// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Coin/CoinHUDUserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetTextLibrary.h"
#include "Actors/Coin/CoinGameState.h"

void UCoinHUDUserWidget::OnGameClear()
{
	ClearText->SetVisibility(ESlateVisibility::Visible);
}

FText UCoinHUDUserWidget::GetRemainCoin()
{
	ACoinGameState* GameState = Cast<ACoinGameState>(UGameplayStatics::GetGameState(this));
	if (!GameState)
	{
		check(false);
		return FText();
	}
	const int32 RemainCoin = GameState->GetRemainCoin();

	// FString: wstring
	// FName: hashed
	// FText: 다국어 처리가 포함된 문자열

	return UKismetTextLibrary::Conv_IntToText(RemainCoin);
}

void UCoinHUDUserWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
}

UCoinHUDUserWidget::UCoinHUDUserWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

bool UCoinHUDUserWidget::Initialize()
{
	bool bResult = Super::Initialize();
	if (ClearText)
	{
		ClearText->SetVisibility(ESlateVisibility::Hidden);
	}
	if (RemainCoinTextBlock)
	{
		RemainCoinTextBlock->TextDelegate.BindDynamic(this, &ThisClass::GetRemainCoin);
	}
	return bResult;
}

void UCoinHUDUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UCoinHUDUserWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UCoinHUDUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCoinHUDUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}
