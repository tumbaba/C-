// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/Notify/AnimNotify_Effect.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WeaponChildActorComponent.h"

UAnimNotify_Effect::UAnimNotify_Effect()
{
#if WITH_EDITORONLY_DATA
	NotifyColor = FColor(255, 0, 0, 255);
#endif // WITH_EDITORONLY_DATA
}

void UAnimNotify_Effect::PlaySound(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (!Sound->IsOneShot())
	{
		UE_LOG(LogAudio, Warning, TEXT("PlaySound notify: Anim %s tried to play a sound asset which is not a one-shot: '%s'. Spawning suppressed."), 
			*GetNameSafe(Animation), *GetNameSafe(Sound));
		return;
	}

	UGameplayStatics::PlaySoundAtLocation(MeshComp->GetWorld(), Sound, MeshComp->GetComponentLocation(), VolumeMultiplier);
}

void UAnimNotify_Effect::PlayParticle(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (PSTemplate->IsLooping())
	{
		UE_LOG(LogTemp, Warning, TEXT("Particle Notify: Anim '%s' tried to spawn infinitely looping particle system '%s'. Spawning suppressed."), *GetNameSafe(Animation), *GetNameSafe(PSTemplate));
		return;
	}

	AActor* OwningActor = MeshComp->GetOwner();
	UWeaponChildActorComponent* WeaponChildActorComponent = OwningActor->GetComponentByClass<UWeaponChildActorComponent>();
	if (!WeaponChildActorComponent && GIsEditor && OwningActor->GetWorld() != GWorld) { return; }// 에디터 프리뷰 에서는 Weapon이 없기 때문에 return 
	
	check(WeaponChildActorComponent);
	AActor* Weapon = WeaponChildActorComponent->GetChildActor();
	check(Weapon);
	USkeletalMeshComponent* WeaponSkeletalMeshComponent = Weapon->GetComponentByClass<USkeletalMeshComponent>();
	check(WeaponSkeletalMeshComponent);

	const FTransform MuzzleTransform = WeaponSkeletalMeshComponent->GetSocketTransform(SocketName);
	FTransform SpawnTransform;
	SpawnTransform.SetLocation(MuzzleTransform.GetLocation());
	SpawnTransform.SetRotation(MuzzleTransform.GetRotation());
	SpawnTransform.SetScale3D(Scale);
	UGameplayStatics::SpawnEmitterAtLocation(MeshComp->GetWorld(), PSTemplate, SpawnTransform);
}

void UAnimNotify_Effect::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (Sound)
	{
		PlaySound(MeshComp, Animation);
	}
	if (PSTemplate)
	{
		PlayParticle(MeshComp, Animation);
	}
}
