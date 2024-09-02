#include "MaterialTexture.h"

// Sets default values
AMaterialTexture::AMaterialTexture()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;

	{
		static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjectFinder(TEXT("/Script/Engine.StaticMesh'/Engine/EngineMeshes/Cube.Cube'"));
		check(ObjectFinder.Object);
		StaticMeshComponent->SetStaticMesh(ObjectFinder.Object);
	}
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> ObjectFinder(TEXT("/Script/Engine.Material'/Game/Blueprint/FirstMap/M_Texture.M_Texture'"));
		check(ObjectFinder.Object);
		StaticMeshComponent->SetMaterial(0, ObjectFinder.Object);
	}
}

// Called when the game starts or when spawned
void AMaterialTexture::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMaterialTexture::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	MID = StaticMeshComponent->CreateDynamicMaterialInstance(0);
	MID->SetVectorParameterValue(TEXT("UV"), UV);
}

// Called every frame
void AMaterialTexture::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UV.X = FMath::Wrap(UV.X + double(DeltaTime) * 0.4, 0.0, 1.0);
	MID->SetVectorParameterValue(TEXT("UV"), UV);
}


