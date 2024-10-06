// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Actors/Item/DroppedItem.h"
#include "Misc/Utils.h"
#include "TPSHUD.generated.h"

/**
 * 
 */
UCLASS()
class KDT3D_API ATPSHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATPSHUD();

protected:
	void AddDroppedItem(ADroppedItem* NewItem);
	void RemoveDroppedItem(ADroppedItem* NewItem);

protected: // InputAction callback
	void OnPickupItem(const FInputActionValue& InputActionValue);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

protected:
	class ATPSPlayerController* PlayerController = nullptr;
	class UTPSHUDUserWidget* Widget = nullptr;

	class UInputMappingContext* IMC_Item = nullptr;

	TArray<AActor*> OverlappedDroppedItems;
};
