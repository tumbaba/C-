// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Misc/Utils.h"
#include "ItemAction.generated.h"

/**
 * 
 */
UCLASS()
class KDT3D_API UItemAction : public UObject
{
	GENERATED_BODY()
public:
	struct FItemContext
	{
		// Item을 사용하는 주체
		APlayerController* User;
		FName ItemName;
	};
	using FContext = FItemContext;

public:
	void SetContext(TUniquePtr<FContext> NewContext) { check(!Context); Context = MoveTemp(NewContext); }

public:
	virtual void Use() { ReleaseContext(); }
	virtual void Equip() { Use(); }
	virtual void Unequip() { ReleaseContext(); }

private:
	void ReleaseContext() { check(Context); Context = nullptr; }

protected:
	TUniquePtr<FContext> Context;
};

UCLASS()
class KDT3D_API UItemAction_Weapon : public UItemAction
{
	GENERATED_BODY()
public:
	virtual void Use();
	virtual void Equip() { Use(); }
};
