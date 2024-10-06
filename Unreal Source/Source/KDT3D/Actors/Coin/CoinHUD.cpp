// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Coin/CoinHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Actors/Coin/CoinGameState.h"
#include "Actors/Coin/CoinHUDUserWidget.h"
#include "Blueprint/UserWidget.h"

ACoinHUD::ACoinHUD()
{
	//static ConstructorHelpers::FClassFinder<UUserWidget> LoadClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/CoinMap/UI_CoinHUD.UI_CoinHUD_C'"));
}

void ACoinHUD::BeginPlay()
{
	Super::BeginPlay();
	
	ACoinGameState* GameState = Cast<ACoinGameState>(UGameplayStatics::GetGameState(this));
	GameState->OnGameClear.AddDynamic(this, &ThisClass::OnGameClear);
	
	// 한번도 참조된 적이 없어서 Load해야 한다.
	UClass* WidgetClass = LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/CoinMap/UI_CoinHUD.UI_CoinHUD_C'"));
	//UClass* WidgetClass = FindObject<UClass>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/CoinMap/UI_CoinHUD.UI_CoinHUD_C'"));
	Widget = CreateWidget<UCoinHUDUserWidget>(GetWorld(), WidgetClass);
	Widget->AddToViewport();
}

void ACoinHUD::OnGameClear()
{
	Widget->OnGameClear();
}
