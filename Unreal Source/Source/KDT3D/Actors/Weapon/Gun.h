// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapon/WeaponBase.h"
#include "Gun.generated.h"

/**
 * 
 */
UCLASS()
class KDT3D_API AGun : public AWeaponBase
{
	GENERATED_BODY()
	
protected:
	virtual void Tick(float DeltaTime) override;

	void UpdateDesiredAimRotation(const float DeltaTime);

protected:
	FRotator DesiredAimRotation;
};
