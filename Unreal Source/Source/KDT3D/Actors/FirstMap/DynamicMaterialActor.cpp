// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FirstMap/DynamicMaterialActor.h"

// Sets default values
ADynamicMaterialActor::ADynamicMaterialActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;
}

// Called when the game starts or when spawned
void ADynamicMaterialActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADynamicMaterialActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (StaticMeshComponent->GetMaterial(0))
	{
		MID = StaticMeshComponent->CreateDynamicMaterialInstance(0);
		check(MID);
		MID->SetVectorParameterValue(TEXT("BaseColor"), BaseColor);
	}
}

// Called every frame
void ADynamicMaterialActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator DeltaRotation;
	DeltaRotation.Pitch = double(DeltaTime) * 360.0;
	//DeltaRotation.Yaw = double(DeltaTime) * 360.0;
	AddActorWorldRotation(DeltaRotation);
}

