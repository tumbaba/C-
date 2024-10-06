// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Item/DroppedItem.h"
#include "Misc/Utils.h"

// Sets default values
ADroppedItem::ADroppedItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<USphereComponent>(TEXT("Collider")))
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Collider = CreateDefaultSubobject<UShapeComponent>(TEXT("Collider"));
	Collider->SetCollisionProfileName(CollisionProfileName::PawnTrigger);
	RootComponent = Collider;

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	SkeletalMeshComponent->SetupAttachment(RootComponent);
	SkeletalMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ADroppedItem::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	SetData(DataTableRowHandle);
}

// Called when the game starts or when spawned
void ADroppedItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADroppedItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	{
		FRotator Rotator{ 0.0, DeltaTime * 360.0, 0.0 };
		AddActorLocalRotation(Rotator);
	}
}

void ADroppedItem::SetData(const FDataTableRowHandle& InDataTableRowHandle)
{
	DataTableRowHandle = InDataTableRowHandle;
	if(DataTableRowHandle.IsNull()) { return; }
	FDroppedItemTableRow* Data = DataTableRowHandle.GetRow<FDroppedItemTableRow>(TEXT("Item"));
	if (!Data) { ensure(false); return; }

	if (Data->SkeletalMesh && Data->StaticMesh)
	{
		ensureMsgf(false, TEXT("둘 중에 하나만 지정 하십시오"));
		return;
	}
	
	SkeletalMeshComponent->SetSkeletalMesh(Data->SkeletalMesh);
	SkeletalMeshComponent->SetRelativeScale3D(Data->Scale);

	StaticMeshComponent->SetStaticMesh(Data->StaticMesh);
	StaticMeshComponent->SetRelativeScale3D(Data->Scale);

	if (USphereComponent* SphereComponent = Cast<USphereComponent>(Collider))
	{
		const float ScaledRadius = FMath::Max3(Data->Scale.X, Data->Scale.Y, Data->Scale.Z);

		if (Data->SkeletalMesh)
		{
			FBoxSphereBounds BoxSphereBounds = Data->SkeletalMesh->GetBounds();
			SphereComponent->SetSphereRadius(ScaledRadius * BoxSphereBounds.SphereRadius);
		}
		else if (Data->StaticMesh)
		{
			FBoxSphereBounds BoxSphereBounds = Data->StaticMesh->GetBounds();
			SphereComponent->SetSphereRadius(ScaledRadius * BoxSphereBounds.SphereRadius);
		}
	}
	
}

void ADroppedItem::UseItem(APlayerController* PC)
{
	if (DataTableRowHandle.IsNull()) { return; }
	FDroppedItemTableRow* Data = DataTableRowHandle.GetRow<FDroppedItemTableRow>(TEXT("Item"));
	if (!Data) { ensure(false); return; }

	UItemAction* ItemAction = Cast<UItemAction>(Data->ItemActionClass->GetDefaultObject());
	if (!ItemAction)
	{
		ensureMsgf(false, TEXT("ItemAction is nullptr"));
		return;
	}

	TUniquePtr<UItemAction::FContext> Context = MakeUnique<UItemAction::FContext>();
	Context->User = PC;
	Context->ItemName = DataTableRowHandle.RowName;
	ItemAction->SetContext(MoveTemp(Context));
	ItemAction->Use();
}
