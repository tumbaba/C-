// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/CelestialBodyDataAsset.h"
#include "CelestialBody.generated.h"

UCLASS()
class KDT3D_API ACelestialBody : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACelestialBody();

	double GetOrbitalSpeed() const { return CelestialBodyData ? CelestialBodyData->OribitalSpeed : 0.0; }

	FVector GetBodyWorldLocation() const { return Body->GetComponentLocation(); }

	void SetCelestialBodyData(UCelestialBodyDataAsset* InData);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Destroyed() override;

	void OnCelestialBodyDataChanged();
	virtual void UpdateDataAsset();

	void CalculateStarLightDirection();

protected:
#if WITH_EDITOR
	virtual void PreEditChange(FProperty* PropertyAboutToChange) override;
#endif

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// OrbitalAxis
	// - RotatingAxis
	//	- Body
	//	- Cloud (Optional)

	// 공전 축
	UPROPERTY(VisibleAnywhere)
	USceneComponent* OrbitalAxis;

	// 자전 축
	UPROPERTY(VisibleAnywhere)
	USceneComponent* RotatingAxis;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Body;

protected: // Optinal
	UPROPERTY()
	UMaterialInstanceDynamic* BodyMID = nullptr;

protected: // Optinal
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Cloud;

protected:
	UPROPERTY(Transient)
	class AStar* ChachedStar = nullptr;

protected:
	UPROPERTY(Category = "CelestialBody", EditAnywhere)
	UCelestialBodyDataAsset* CelestialBodyData;
	FDelegateHandle CelestialBodyDataUpdateHandle;
};
