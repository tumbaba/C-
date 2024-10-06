// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Weapon/Gun.h"
#include "Kismet/KismetMathLibrary.h"

void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateDesiredAimRotation(DeltaTime);
}

void AGun::UpdateDesiredAimRotation(const float DeltaTime)
{
	{
		const FRotator OwnerRotation = OwningPawn->GetActorRotation();
		FRotator OwnerInvRotation = OwnerRotation.GetInverse();
		OwnerInvRotation.Roll = 0.;
		FRotator ControlRotation = OwningPawn->GetControlRotation();
		ControlRotation.Roll = 0.;
		FRotator NewRotation = UKismetMathLibrary::ComposeRotators(OwnerInvRotation, ControlRotation);
		
		DesiredAimRotation.Pitch = NewRotation.Pitch;
		DesiredAimRotation.Yaw = UKismetMathLibrary::ClampAngle(NewRotation.Yaw, -100.0, 100.0);
		DesiredAimRotation.Roll = NewRotation.Roll;
	}
	{
		const FRotator& AimRotation = BasicAnimInstance->GetAimRotation();
		const float Alpha = DeltaTime * 10.f;
		const FRotator LerpShortestPathRotation = UKismetMathLibrary::RLerp(AimRotation, DesiredAimRotation, Alpha, true);
		const FRotator LerpRotation = UKismetMathLibrary::RLerp(AimRotation, DesiredAimRotation, Alpha, false);
		const FRotator NewRotation = FRotator(LerpShortestPathRotation.Pitch, LerpRotation.Yaw, LerpShortestPathRotation.Roll);
		BasicAnimInstance->SetAimRotation(NewRotation);
	}
}
