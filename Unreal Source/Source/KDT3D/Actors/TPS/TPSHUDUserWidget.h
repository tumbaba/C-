// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "TPSHUDUserWidget.generated.h"

class ADroppedItem;

UCLASS()
class KDT3D_API UTPSHUDUserWidget : public UUserWidget
{
	GENERATED_BODY()

	friend class ATPSHUD;

protected:
	void AddDroppedItem(ADroppedItem* NewItem);
	void RemoveDroppedItem(ADroppedItem* NewItem);

protected:
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "AddDroppedItem"))
	void ReceiveAddDroppedItem();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "RemoveDroppedItem"))
	void ReceiveRemoveDroppedItem();

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UVerticalBox* DroppedItemDescVerticalBox = nullptr;
};
