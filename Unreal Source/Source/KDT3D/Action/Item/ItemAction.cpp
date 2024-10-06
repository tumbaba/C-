// Fill out your copyright notice in the Description page of Project Settings.


#include "Action/Item/ItemAction.h"
#include "Subsystem/ItemSubsystem.h"
#include "Actors/Weapon/WeaponBase.h"
#include "GameFramework/Character.h"
#include "Components/WeaponChildActorComponent.h"

void UItemAction_Weapon::Use()
{
	if (UWorld* World = Context->User->GetWorld())
	{
		UItemSubsystem* Subsystem = World->GetGameInstance()->GetSubsystem<UItemSubsystem>();
		FDataTableRowHandle Handle = Subsystem->FindItem(Context->ItemName);
		if (Handle.IsNull())
		{
			ensureMsgf(false, TEXT("Handle is not valid"));
			return;
		}

		APawn* Pawn = Context->User->GetPawn();
		UWeaponChildActorComponent* Weapon = Pawn->GetComponentByClass<UWeaponChildActorComponent>();
		check(Weapon);
		Weapon->SetData(Handle);

		//AWeaponBase* Weapon = World->SpawnActorDeferred<AWeaponBase>(AWeaponBase::StaticClass(),
		//	FTransform::Identity, Pawn);
		//Weapon->DataTableRowHandle = Handle;
		//
		//USkeletalMeshComponent* SkeletalMeshComponent = Pawn->GetComponentByClass<USkeletalMeshComponent>();
		//check(SkeletalMeshComponent);
		//{
		//	Weapon->AttachToComponent(SkeletalMeshComponent, FAttachmentTransformRules::KeepRelativeTransform, 
		//		SocketName::Weapon);
		//}
		//Weapon->FinishSpawning(FTransform::Identity);
	}

	Super::Use();
}
