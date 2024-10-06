// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Components/ShapeComponent.h"
#include "BaseTriggerBox.generated.h"

UINTERFACE()
class UTriggerInterface : public UInterface
{
	GENERATED_BODY()
};

class ITriggerInterface
{
	GENERATED_BODY()

public:
	// Trigger 활성화 범위에 들어옴
	UFUNCTION(BlueprintNativeEvent)
	void OnActive(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void OnActive_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {}
	
	// Trigger 활성화 범위에서 나감
	UFUNCTION(BlueprintNativeEvent)
	void OnDeactive(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	virtual void OnDeactive_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {}

	// Trigger 최종 활성화 범위에 들어옴
	UFUNCTION(BlueprintNativeEvent)
	void OnTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void OnTrigger_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {}
};

UCLASS()
class KDT3D_API ABaseTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	ABaseTriggerBox(const FObjectInitializer& ObjectInitializer);

protected:
#if WITH_EDITOR
	/**
	 * Called after importing property values for this object (paste, duplicate or .t3d import)
	 * Allow the object to perform any cleanup for properties which shouldn't be duplicated or
	 * are unsupported by the script serialization
	 */
	virtual void PostEditImport() override;
#endif

protected:
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Destroyed() override;

protected:
	void UpdateBoxExtent();

protected:
	UFUNCTION()
	void OnActivate(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnDeactivate(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
	void OnTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UShapeComponent> ActiveCollisionComponent;

protected:
	UPROPERTY(EditAnywhere, meta = (MustImplement = "TriggerInterface"))
	TSoftClassPtr<AActor> ActorToSpawn;
	
	UPROPERTY()
	AActor* SpawnedActor = nullptr;
};
