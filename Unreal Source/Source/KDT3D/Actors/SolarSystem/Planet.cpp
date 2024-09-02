// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SolarSystem/Planet.h"

void APlanet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (ACelestialBody* CelestialBody : Moons)
	{
		const double Speed = CelestialBody->GetOrbitalSpeed() * DeltaTime;
		FRotator Rotator(0.0, Speed, 0.0);
		CelestialBody->AddActorLocalRotation(Rotator);
		//CelestialBody->AddActorWorldRotation(Rotator);
	}
}

void APlanet::Destroyed()
{
	Super::Destroyed();

#if WITH_EDITOR
	if (GIsEditor && !FApp::IsGame())
	{
		for (ACelestialBody* CelestialBody : Moons)
		{
			if (CelestialBody)
			{
				CelestialBody->Destroy();
			}
		}
	}
#endif
}

#if WITH_EDITOR

void APlanet::PreEditChange(FProperty* PropertyAboutToChange)
{
	Super::PreEditChange(PropertyAboutToChange);
	const FString PropertyName = PropertyAboutToChange->GetName();
	if (PropertyName == GET_MEMBER_NAME_CHECKED(ThisClass, Moons))
	{
		PrevMoons = Moons;
	}
}

void APlanet::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	const FString PropertyName = PropertyChangedEvent.Property->GetName();
	if (PropertyName == GET_MEMBER_NAME_CHECKED(ThisClass, Moons))
	{
		const int32 Index = PropertyChangedEvent.GetArrayIndex(PropertyName);
		switch (PropertyChangedEvent.ChangeType)
		{
		case EPropertyChangeType::ArrayAdd:
		{
			Moons[Index] = AddMoon();
			break;
		}
		case EPropertyChangeType::ArrayRemove:
		{
			if (PrevMoons[Index])
			{
				ACelestialBody* CelestialBody = PrevMoons[Index];
				CelestialBody->Destroy();
			}
			break;
		}
		case EPropertyChangeType::Duplicate:
		{
			if (PrevMoons[Index])
			{
				Moons[Index] = AddMoon(PrevMoons[Index]);
			}
			break;
		}
		case EPropertyChangeType::ArrayClear:
		{
			for (ACelestialBody* CelestialBody : PrevMoons)
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
		PrevMoons.Empty();
	}
}

ACelestialBody* APlanet::AddMoon(ACelestialBody* InTemplate)
{
	UWorld* World = GetWorld();
	FActorSpawnParameters ActorSpawnParameters;
	//ActorSpawnParameters.Owner = this;
	ActorSpawnParameters.Template = InTemplate;
	ActorSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ActorSpawnParameters.TransformScaleMethod = ESpawnActorScaleMethod::OverrideRootScale;

	const FTransform NewTransform = InTemplate ? InTemplate->GetTransform() : GetTransform();
	ACelestialBody* CelestialBody = World->SpawnActor<ACelestialBody>(ACelestialBody::StaticClass(), NewTransform, ActorSpawnParameters);

	if (!InTemplate)
	{
		CelestialBody->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
	}

	return CelestialBody;
}

#endif