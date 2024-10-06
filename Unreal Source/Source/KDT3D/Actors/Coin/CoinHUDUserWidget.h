// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "CoinHUDUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class KDT3D_API UCoinHUDUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void OnGameClear();

	UFUNCTION()
	FText GetRemainCoin();

public:
	virtual void SynchronizeProperties() override;
	UCoinHUDUserWidget(const FObjectInitializer& ObjectInitializer);
	virtual bool Initialize() override;
	virtual void NativeOnInitialized() override;
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);

protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* RemainCoinTextBlock = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* ClearText = nullptr;
};
