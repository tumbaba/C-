// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/WeaponChildActorComponent.h"
#include "Actors/Weapon/WeaponBase.h"

UWeaponChildActorComponent::UWeaponChildActorComponent()
{
	SetChildActorClass(AWeaponBase::StaticClass());
}

void UWeaponChildActorComponent::SetData(FDataTableRowHandle InDataTableRowHandle)
{
	if (InDataTableRowHandle.IsNull()) { return; }
	FWeaponTableRow* Data = InDataTableRowHandle.GetRow<FWeaponTableRow>(TEXT("Weapon"));
	if (!Data) { ensure(false); return; }

	if (GetChildActorClass() != Data->WeaponClass)
	{
		SetChildActorClass(Data->WeaponClass);
	}

	AWeaponBase* Weapon = Cast<AWeaponBase>(GetChildActor());
	check(Weapon);
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	check(OwnerPawn);
	Weapon->SetOwner(OwnerPawn);
	Weapon->SetInstigator(OwnerPawn);
	Weapon->SetData(InDataTableRowHandle);
}
