// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Planet.h"
#include "Star.h"
#include "Data/StarDataAsset.h"
#include "SolarSystem.generated.h"

UCLASS()
class KDT3D_API ASolarSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASolarSystem();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Destroyed() override;

	void UpdateStarData();

protected:
	APlanet* AddPlanet(APlanet* InTemplate = nullptr);

protected:
#if WITH_EDITOR
	virtual void PreEditChange(FProperty* PropertyAboutToChange) override;
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	TArray<APlanet*> PrevPlanets;
#endif

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultSceneRoot = nullptr;

	UPROPERTY(VisibleAnywhere)
	UChildActorComponent* StarChildActorComponent;
	
	UPROPERTY(EditAnywhere)
	UStarDataAsset* StarBodyData;

	UPROPERTY(EditAnywhere)
	TArray<APlanet*> Planets;
};
