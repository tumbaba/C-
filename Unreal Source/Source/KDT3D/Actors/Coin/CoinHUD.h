// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CoinHUD.generated.h"

/**
 * 
 */
UCLASS()
class KDT3D_API ACoinHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	ACoinHUD();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnGameClear();

protected:
	class UCoinHUDUserWidget* Widget;
};
