// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "CoinGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FOnGameClear, ACoinGameState, OnGameClear);

/**
 * 
 */
UCLASS()
class KDT3D_API ACoinGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	int32 GetRemainCoin() const { return RemainCoin; }

protected:
	virtual void BeginPlay() override;

protected:
	UFUNCTION()
	void OnCoinDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void OnLevelTransition();

public:
	FOnGameClear OnGameClear;

protected:
	UPROPERTY(BlueprintReadOnly)
	int32 RemainCoin = 0;
};
