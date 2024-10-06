// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/TPS/TPSHUDUserWidget.h"
#include "Actors/Item/DroppedItem.h"

void UTPSHUDUserWidget::AddDroppedItem(ADroppedItem* NewItem)
{
	ReceiveAddDroppedItem();
	//DroppedItemDescVerticalBox->AddChild();
}

void UTPSHUDUserWidget::RemoveDroppedItem(ADroppedItem* NewItem)
{
	ReceiveRemoveDroppedItem();
}
