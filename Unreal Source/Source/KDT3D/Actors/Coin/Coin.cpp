// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Coin/Coin.h"
#include "Components/TimelineComponent.h"

// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OnActorBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
}

void ACoin::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	SetActorEnableCollision(false);
	RotationSpeed = 2.f;
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float Speed = DeltaTime * 360.f * RotationSpeed;
	const FRotator Rotator = FRotator(0.0, Speed, 0.0);
	AddActorLocalRotation(Rotator);
}

