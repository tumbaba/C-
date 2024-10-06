// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_Effect.generated.h"

class USoundBase;
class UParticleSystem;

UCLASS()
class KDT3D_API UAnimNotify_Effect : public UAnimNotify
{
	GENERATED_BODY()

public:
	UAnimNotify_Effect();

protected:
	virtual void PlaySound(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation);
	virtual void PlayParticle(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation);

public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

public: // Sound
	// Sound to Play
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimNotify|Sound", meta = (ExposeOnSpawn = true))
	TObjectPtr<USoundBase> Sound;

	// Volume Multiplier
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimNotify|Sound", meta = (ExposeOnSpawn = true))
	float VolumeMultiplier;

public: // Particle
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimNotify|Particle", meta = (DisplayName = "Particle System"))
	TObjectPtr<UParticleSystem> PSTemplate;

	// Scale to spawn the particle system at
	UPROPERTY(EditAnywhere, Category = "AnimNotify|Particle")
	FVector Scale = FVector::OneVector;

	// SocketName to attach to
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimNotify")
	FName SocketName = TEXT("Muzzle");
};
