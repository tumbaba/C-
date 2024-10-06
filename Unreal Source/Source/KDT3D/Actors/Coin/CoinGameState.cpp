// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Coin/CoinGameState.h"
#include "Actors/Coin/Coin.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void ACoinGameState::BeginPlay()
{
	Super::BeginPlay();

	//UClass* CoinClass = FindObject<UClass>(nullptr, TEXT("/Script/Engine.Blueprint'/Game/Blueprint/CoinMap/BP_Coin.BP_Coin_C'"));
	TArray<AActor*> Result;
	UGameplayStatics::GetAllActorsOfClass(this, ACoin::StaticClass(), Result);

	for (AActor* Actor : Result)
	{
		Actor->OnDestroyed.AddDynamic(this, &ThisClass::OnCoinDestroyed);
	}

	RemainCoin = Result.Num();
	if (RemainCoin == 0)
	{
		check(false);
	}
}

void ACoinGameState::OnCoinDestroyed(AActor* DestroyedActor)
{
	--RemainCoin;

	if (RemainCoin == 0)
	{
		OnGameClear.Broadcast();
		UKismetSystemLibrary::K2_SetTimer(this, TEXT("OnLevelTransition"), 3.f, false);
	}
}

void ACoinGameState::OnLevelTransition()
{
	UGameplayStatics::OpenLevel(this, TEXT("LobbyMap"));
}
