//////cpp
////// Fill out your copyright notice in the Description page of Project Settings.
////
////
////#include "Actors/SolarSystem/SolarSystem.h"
////
////// Sets default values
////ASolarSystem::ASolarSystem()
////{
////	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
////	PrimaryActorTick.bCanEverTick = true;
////
////	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
////	RootComponent = DefaultSceneRoot;
////
////	StarChildActorComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("Star"));
////	StarChildActorComponent->SetupAttachment(RootComponent);
////	StarChildActorComponent->SetChildActorClass(AStar::StaticClass());
////}
////
////void ASolarSystem::OnConstruction(const FTransform& Transform)
////{
////	Super::OnConstruction(Transform);
////
////	UpdateStarData();
////}
////
////// Called when the game starts or when spawned
////void ASolarSystem::BeginPlay()
////{
////	Super::BeginPlay();
////
////}
////
////void ASolarSystem::UpdateStarData()
////{
////	AStar* Star = Cast<AStar>(StarChildActorComponent->GetChildActor());
////	if (Star && StarBodyData)
////	{
////		Star->SetCelestialBodyData(StarBodyData);
////	}
////}
////
////#if WITH_EDITOR
////void ASolarSystem::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
////{
////	Super::PostEditChangeProperty(PropertyChangedEvent);
////	UpdateStarData();
////	const FString PropertyName = PropertyChangedEvent.Property->GetName();
////	if (PropertyName == GET_MEMBER_NAME_CHECKED(ThisClass, Planets))
////	{
////		const int32 Index = PropertyChangedEvent.GetArrayIndex(PropertyName);
////		switch (PropertyChangedEvent.ChangeType)
////		{
////		case EPropertyChangeType::ArrayAdd:
////		{
////			Planets[Index] = AddPlanet();
////			break;
////		}
////		case EPropertyChangeType::ArrayRemove:
////		{
////			if (PrevPlanets[Index])
////			{
////				ACelestialBody* CelestialBody = PrevPlanets[Index];
////				CelestialBody->Destroy();
////			}
////			break;
////		}
////		case EPropertyChangeType::Duplicate:
////		{
////			if (PrevPlanets[Index])
////			{
////				Planets[Index] = AddPlanet(PrevPlanets[Index]);
////			}
////			break;
////		}
////		case EPropertyChangeType::ArrayClear:
////		{
////			for (ACelestialBody* CelestialBody : PrevPlanets)
////			{
////				if (CelestialBody)
////				{
////					CelestialBody->Destroy();
////				}
////			}
////			break;
////		}
////		default:
////			check(false);
////			break;
////		}
////		PrevPlanets.Empty();
////	}
////}
////#endif
////
////// Called every frame
////void ASolarSystem::Tick(float DeltaTime)
////{
////	Super::Tick(DeltaTime);
////
////	for (APlanet* CelestialBody : Planets)
////	{
////		const double Speed = CelestialBody->GetOrbitalSpeed() * DeltaTime;
////		FRotator Rotator(0.0, Speed, 0.0);
////		CelestialBody->AddActorLocalRotation(Rotator);
////		//CelestialBody->AddActorWorldRotation(Rotator);
////	}
////
////}
////
////APlanet* ASolarSystem::AddPlanet(ACelestialBody* InTemplate)
////{
////	UWorld* World = GetWorld();
////	FActorSpawnParameters ActorSpawnParameters;
////	//ActorSpawnParameters.Owner = this;
////	ActorSpawnParameters.Template = InTemplate;
////	ActorSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
////	ActorSpawnParameters.TransformScaleMethod = ESpawnActorScaleMethod::OverrideRootScale;
////
////
////	const FTransform NewTransform = InTemplate ? InTemplate->GetTransform() : StarChildActorComponent->GetComponentTransform();
////	APlanet* CelestialBody = World->SpawnActor<APlanet>(APlanet::StaticClass(), NewTransform, ActorSpawnParameters);
////
////	if (!InTemplate)
////	{
////		CelestialBody->AttachToComponent(StarChildActorComponent, FAttachmentTransformRules::KeepWorldTransform);
////	}
////
////	return CelestialBody;
////}
////h
//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "GameFramework/Actor.h"
//#include "Planet.h"
//#include "Star.h"
//#include "Data/StarDataAsset.h"
//#include "SolarSystem.generated.h"
//
//UCLASS()
//class KDT3D_API ASolarSystem : public AActor
//{
//	GENERATED_BODY()
//
//public:
//	// Sets default values for this actor's properties
//	ASolarSystem();
//
//protected:
//	virtual void OnConstruction(const FTransform& Transform) override;
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//	void UpdateStarData();
//
//protected:
//#if WITH_EDITOR
//	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
//#endif
//
//public:
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//
//protected:
//	APlanet* AddPlanet(ACelestialBody* InTemplate = nullptr);
//
//	TArray<ACelestialBody*> PrevPlanets;
//
//protected:
//	UPROPERTY(VisibleAnywhere)
//	USceneComponent* DefaultSceneRoot = nullptr;
//
//	UPROPERTY(VisibleAnywhere)
//	UChildActorComponent* StarChildActorComponent;
//
//	UPROPERTY(EditAnywhere)
//	UStarDataAsset* StarBodyData;
//
//	UPROPERTY(EditAnywhere)
//	TArray<APlanet*> Planets;
//
//
//
//};
