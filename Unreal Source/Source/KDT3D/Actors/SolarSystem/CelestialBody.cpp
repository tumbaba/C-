// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SolarSystem/CelestialBody.h"
#include "Actors/SolarSystem/Star.h"
#include "Kismet/GameplayStatics.h"

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

void ACelestialBody::SetCelestialBodyData(UCelestialBodyDataAsset* InData)
{
	CelestialBodyData = InData;
	OnConstruction(GetActorTransform());
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
#if WITH_EDITOR
		CelestialBodyDataUpdateHandle = CelestialBodyData->OnCelestialBodyDataAssetChanged.AddUObject(this, &ThisClass::OnCelestialBodyDataChanged);
#endif
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

	if (CelestialBodyData->BodyMaterial && CelestialBodyData->bDynamicMaterialInstance)
	{
		BodyMID = Body->CreateDynamicMaterialInstance(0);
	}

	if (CelestialBodyData->bCloud && Cloud == nullptr)
	{
		Cloud = NewObject<UStaticMeshComponent>(this, TEXT("Cloud"));
		Cloud->RegisterComponent();
		Cloud->AttachToComponent(Body, FAttachmentTransformRules::KeepRelativeTransform);
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

	if (CelestialBodyData->bCalculateStarLightDirection)
	{
		CalculateStarLightDirection();
	}
}

void ACelestialBody::CalculateStarLightDirection()
{
	if (!Cloud)
	{
		return;
	}
	if (!ChachedStar)
	{
		ChachedStar = Cast<AStar>(UGameplayStatics::GetActorOfClass(this, AStar::StaticClass()));
		if (!ChachedStar)
		{
			// 공간상에 Star가 없습니다.
			ensure(false);
			return;
		}
#if WITH_EDITOR
		ChachedStar->OnStarDataAssetChanged.AddUObject(this, &ThisClass::CalculateStarLightDirection);
#endif
	}

	const FVector MyLocation = GetBodyWorldLocation();
	const FVector StarLocation = ChachedStar->GetBodyWorldLocation();

	// 나에서 Star로 향하는 Vector를 구한다
	// 벡터의 뺄셈은 뒤Vector(MyLocation)에서 앞Vector(StarLocation)로 향하는 Vector를 만든다
	const FVector Vector = StarLocation - MyLocation;

	// Vector를 Normalize해서(단위 Vector로 만들기) 크기 성분을 지우고 방향 정보만 남긴다
	FVector DirectionVector = Vector;
	DirectionVector.Normalize();
	const FName MID_LightDirection = TEXT("LightDirection");
	BodyMID->SetVectorParameterValue(MID_LightDirection, DirectionVector);

	if (CelestialBodyData->OverlayMaterial && Cloud->OverlayMaterial)
	{
		UMaterialInstanceDynamic* MID = Cast<UMaterialInstanceDynamic>(Cloud->OverlayMaterial);
		if (MID)
		{
			MID->SetVectorParameterValue(MID_LightDirection, DirectionVector);
		}
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
		Body->AddLocalRotation(Rotator);
	}

	if (Cloud)
	{
		const double Speed = CelestialBodyData->CloudRotatingSpeed * DeltaTime;
		FRotator Rotator(0.0, Speed, 0.0);
		Cloud->AddLocalRotation(Rotator);
	}

	if (CelestialBodyData->bCalculateStarLightDirection)
	{
		CalculateStarLightDirection();
	}
}

