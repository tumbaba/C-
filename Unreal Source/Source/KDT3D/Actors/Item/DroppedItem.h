// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Action/Item/ItemAction.h"
#include "DroppedItem.generated.h"

USTRUCT()
struct KDT3D_API FDroppedItemTableRow : public FTableRowBase
{
	GENERATED_BODY()

	// SkeletalMesh 또는 StaticMesh를 선택하면 둘 중 유요한 하나를 사용해서 Mesh로 띄워준다
	UPROPERTY(EditAnywhere, Category = "Item")
	USkeletalMesh* SkeletalMesh = nullptr;

	// SkeletalMesh 또는 StaticMesh를 선택하면 둘 중 유요한 하나를 사용해서 Mesh로 띄워준다
	UPROPERTY(EditAnywhere, Category = "Item")
	UStaticMesh* StaticMesh = nullptr;

	UPROPERTY(EditAnywhere, Category = "Item")
	FVector Scale = FVector(2.0, 2.0, 2.0);

	UPROPERTY(EditAnywhere, Category = "Item")
	TSubclassOf<UItemAction> ItemActionClass = UItemAction::StaticClass();
};

UCLASS()
class KDT3D_API ADroppedItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADroppedItem(const FObjectInitializer& ObjectInitializer);
	virtual void SetData(const FDataTableRowHandle& InDataTableRowHandle);
	virtual void UseItem(APlayerController* PC);

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// [Root] ShapeComponent (기본은 Sphere로 만들어지며, 자식에서 변경하고자 하면 변경 하시오)
	// 참고: ObjectInitializer.SetDefaultSubobjectClass<UBoxComponent>
	// - SkeletalMeshComponent
	// - StaticMeshComponent
	//	참고: SkeletalMesh 또는 StaticMesh 둘 중 하나를 사용할 수 있도록 2개를 만들어둠

	UPROPERTY(VisibleAnywhere)
	UShapeComponent* Collider;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

protected:
	UPROPERTY(EditAnywhere, meta = (RowType="/Script/KDT3D.DroppedItemTableRow"))
	FDataTableRowHandle DataTableRowHandle;
};
