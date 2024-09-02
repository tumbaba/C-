#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MaterialTexture.generated.h"

UCLASS()
class KDT3D_API AMaterialTexture : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMaterialTexture();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere)
	FVector4 UV = FVector4(0.0, 0.0, 1.0, 1.0);

protected:
	UPROPERTY()
	UMaterialInstanceDynamic* MID = nullptr;
};
