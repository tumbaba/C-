// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/TPS/TPSCharacter.h"

ATPSCharacter::ATPSCharacter()
{
	SpringArm->SetRelativeLocation(FVector(0., 0., 160.));
	Camera->SetRelativeLocation(FVector(0., 140., 0.));
}