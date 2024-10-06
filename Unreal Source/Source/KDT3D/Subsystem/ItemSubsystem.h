// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ItemSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class KDT3D_API UItemSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UItemSubsystem();

	FDataTableRowHandle FindItem(const FName& InKey);

protected:
	UDataTable* WeaponDataTable;
};
