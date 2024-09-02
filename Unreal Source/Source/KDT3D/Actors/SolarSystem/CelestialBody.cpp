// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SolarSystem/CelestialBody.h"

// Sets default values
ACelestialBody::ACelestialBody()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OrbitalAxis = CreateDefaultSubobject<USceneComponent>(TEXT("OrbitalAxis"));
	RootComponent = OrbitalAxis;

	RotatingAxis = CreateDefaultSubobject<USceneComponent>(TEXT("RotatingAxis"));
	RotatingAxis->SetupAttachment(RootComponent);

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(RotatingAxis);
}

// Called when the game starts or when spawned
void ACelestialBody::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACelestialBody::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (CelestialBodyData)
	{
		CelestialBodyDataUpdateHandle = CelestialBodyData->OnCelestialBodyDataAssetChanged.AddUObject(this, &ThisClass::OnCelestialBodyDataChanged);
		UpdateDataAsset();
	}
}

void ACelestialBody::Destroyed()
{
	Super::Destroyed();
}

void ACelestialBody::OnCelestialBodyDataChanged()
{
	UpdateDataAsset();
}

void ACelestialBody::UpdateDataAsset()
{
	if (!CelestialBodyData) { return; }

	Body->SetStaticMesh(CelestialBodyData->BodyMesh);
	Body->SetRelativeScale3D(CelestialBodyData->BodyScale3D);
	Body->SetMaterial(0, CelestialBodyData->BodyMaterial);

	if (CelestialBodyData->bCloud && Cloud == nullptr)
	{
		Cloud = NewObject<UStaticMeshComponent>(this, TEXT("Cloud"));
		Cloud->RegisterComponent();
		Cloud->AttachToComponent(RotatingAxis, FAttachmentTransformRules::KeepRelativeTransform);
	}
	else if (CelestialBodyData->bCloud == false && Cloud)
	{
		Cloud->DestroyComponent();
		Cloud = nullptr;
	}

	if (Cloud)
	{
		Cloud->SetRelativeScale3D(CelestialBodyData->CloudScale3D);
		Cloud->SetStaticMesh(CelestialBodyData->CloudMesh);
		Cloud->SetMaterial(0, CelestialBodyData->CloudMaterial);

		UMaterialInterface* MaterialInstance = nullptr;
		if (CelestialBodyData->OverlayMaterial)
		{
			MaterialInstance = CelestialBodyData->OverlayMaterial;
			UMaterialInstanceDynamic* MID = Cast<UMaterialInstanceDynamic>(MaterialInstance);
			if (MaterialInstance && !MID)
			{
				MID = UMaterialInstanceDynamic::Create(MaterialInstance, Cloud, NAME_None);
				MaterialInstance = MID;

				MID->SetVectorParameterValue(TEXT("Color"), CelestialBodyData->OverlayColor);
			}
		}
		Cloud->SetOverlayMaterial(MaterialInstance);
	}
}

#if WITH_EDITOR
void ACelestialBody::PreEditChange(FProperty* PropertyAboutToChange)
{
	Super::PreEditChange(PropertyAboutToChange);
	const FString PropertyName = PropertyAboutToChange->GetName();
	if (PropertyName == GET_MEMBER_NAME_CHECKED(ThisClass, CelestialBodyData))
	{
		if (CelestialBodyData)
		{
			CelestialBodyData->OnCelestialBodyDataAssetChanged.Remove(CelestialBodyDataUpdateHandle);
		}
	}
}
#endif

// Called every frame
void ACelestialBody::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!CelestialBodyData) { return; }

	{
		const double Speed = CelestialBodyData->RotatingSpeed * DeltaTime;
		FRotator Rotator(0.0, Speed, 0.0);
		Body->AddRelativeRotation(Rotator);
	}

	if (Cloud)
	{
		const double Speed = CelestialBodyData->CloudRotatingSpeed * DeltaTime;
		FRotator Rotator(0.0, Speed, 0.0);
		Cloud->AddRelativeRotation(Rotator);
	}
}

