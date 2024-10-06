// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Trigger/TriggerTestActor.h"

// Sets default values
ATriggerTestActor::ATriggerTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATriggerTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATriggerTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATriggerTestActor::OnTrigger_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OnTrigger!"));
}