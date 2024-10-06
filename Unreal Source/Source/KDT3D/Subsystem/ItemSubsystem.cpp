// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystem/ItemSubsystem.h"

UItemSubsystem::UItemSubsystem()
{
	{
		static ConstructorHelpers::FObjectFinder<UDataTable> Asset(TEXT("/Script/Engine.DataTable'/Game/Blueprint/Weapon/DT_Weapon.DT_Weapon'"));
		check(Asset.Object);
		WeaponDataTable = Asset.Object;
	}
}

FDataTableRowHandle UItemSubsystem::FindItem(const FName& InKey)
{
	if (WeaponDataTable->GetRowMap().Find(InKey))
	{
		FDataTableRowHandle DataTableRowHandle;
		DataTableRowHandle.DataTable = WeaponDataTable;
		DataTableRowHandle.RowName = InKey;
		return DataTableRowHandle;
	}
	return FDataTableRowHandle();
}
