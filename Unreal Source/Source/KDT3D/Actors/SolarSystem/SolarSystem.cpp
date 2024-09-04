// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SolarSystem/SolarSystem.h"

// Sets default values
ASolarSystem::ASolarSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	StarChildActorComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("Star"));
	StarChildActorComponent->SetupAttachment(RootComponent);
	StarChildActorComponent->SetChildActorClass(AStar::StaticClass());
}

void ASolarSystem::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	UpdateStarData();
}

// Called when the game starts or when spawned
void ASolarSystem::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASolarSystem::Destroyed()
{
	Super::Destroyed();

#if WITH_EDITOR
	if (GIsEditor && !FApp::IsGame())
	{
		for (APlanet* Planet : Planets)
		{
			if (Planet)
			{
				Planet->Destroy();
			}
		}
	}
#endif
}

void ASolarSystem::UpdateStarData()
{
	AStar* Star = Cast<AStar>(StarChildActorComponent->GetChildActor());
	if (Star && StarBodyData)
	{
		Star->SetCelestialBodyData(StarBodyData);
	}
}

APlanet* ASolarSystem::AddPlanet(APlanet* InTemplate)
{
	UWorld* World = GetWorld();
	FActorSpawnParameters ActorSpawnParameters;
	//ActorSpawnParameters.Owner = this;
	ActorSpawnParameters.Template = InTemplate;
	ActorSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ActorSpawnParameters.TransformScaleMethod = ESpawnActorScaleMethod::OverrideRootScale;

	const FTransform NewTransform = InTemplate ? InTemplate->GetTransform() : GetTransform();
	APlanet* Planet = World->SpawnActor<APlanet>(APlanet::StaticClass(), NewTransform, ActorSpawnParameters);

	if (!InTemplate)
	{
		Planet->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
	}

	return Planet;
}

#if WITH_EDITOR
void ASolarSystem::PreEditChange(FProperty* PropertyAboutToChange)
{
	Super::PreEditChange(PropertyAboutToChange);
	const FString PropertyName = PropertyAboutToChange->GetName();
	if (PropertyName == GET_MEMBER_NAME_CHECKED(ThisClass, Planets))
	{
		PrevPlanets = Planets;
	}
}
void ASolarSystem::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	UpdateStarData();
	const FString PropertyName = PropertyChangedEvent.Property->GetName();
	
	if (PropertyName == GET_MEMBER_NAME_CHECKED(ThisClass, Planets))
	{
		const int32 Index = PropertyChangedEvent.GetArrayIndex(PropertyName);
		switch (PropertyChangedEvent.ChangeType)
		{
		case EPropertyChangeType::ArrayAdd:
		{
			Planets[Index] = AddPlanet();
			break;
		}
		case EPropertyChangeType::ArrayRemove:
		{
			if (PrevPlanets[Index])
			{
				ACelestialBody* CelestialBody = PrevPlanets[Index];
				CelestialBody->Destroy();
			}
			break;
		}
		case EPropertyChangeType::Duplicate:
		{
			if (PrevPlanets[Index])
			{
				Planets[Index] = AddPlanet(PrevPlanets[Index]);
			}
			break;
		}
		case EPropertyChangeType::ArrayClear:
		{
			for (ACelestialBody* CelestialBody : PrevPlanets)
			{
				if (CelestialBody)
				{
					CelestialBody->Destroy();
				}
			}
			break;
		}
		default:
			check(false);
			break;
		}
		PrevPlanets.Empty();
	}
}
#endif

// Called every frame
void ASolarSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	for (APlanet* Planet : Planets)
	{
		const double Speed = Planet->GetOrbitalSpeed() * DeltaTime;
		FRotator Rotator(0.0, Speed, 0.0);
		Planet->AddActorLocalRotation(Rotator);
	}
}

