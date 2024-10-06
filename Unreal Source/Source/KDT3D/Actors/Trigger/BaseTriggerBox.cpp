// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Trigger/BaseTriggerBox.h"
#include "Components/BoxComponent.h"
#include "Misc/Utils.h"

ABaseTriggerBox::ABaseTriggerBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UBoxComponent>(TEXT("ActiveCollisionComp")))
{
	bGenerateOverlapEventsDuringLevelStreaming = true;
	ActiveCollisionComponent = CreateDefaultSubobject<UShapeComponent>(TEXT("ActiveCollisionComp"));

	ActiveCollisionComponent->SetupAttachment(RootComponent);
	ActiveCollisionComponent->SetCollisionProfileName(CollisionProfileName::PawnTrigger);

	UShapeComponent* ShapeComponent = GetCollisionComponent();
	ShapeComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnTrigger);
	ActiveCollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnActivate);
	ActiveCollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnDeactivate);
}

void ABaseTriggerBox::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseTriggerBox::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	UClass* ActorClass = ActorToSpawn.LoadSynchronous();

	if (SpawnedActor && SpawnedActor->GetClass() != ActorClass)
	{
		SpawnedActor->Destroy();
		SpawnedActor = nullptr;
	}

	if (ActorClass)
	{
		const bool bInterface = ActorClass->ImplementsInterface(UTriggerInterface::StaticClass());
		// UPROPERTY(EditAnywhere, meta = (MustImplement = "TriggerInterface"))
		// 로 대응 가능
		/*if (!bInterface)
		{
			ensureAlwaysMsgf(false, TEXT("%s is not Implements UTriggerInterface"), *ActorToSpawn->GetName());
			ActorToSpawn = nullptr;
		}*/

		if (bInterface && !SpawnedActor)
		{
			FActorSpawnParameters ActorSpawnParameters;
			//ActorSpawnParameters.ObjectFlags = RF_Transient; // 저장을 하지마라 라는 키워드
			ActorSpawnParameters.Owner = this;
			SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorClass, ActorSpawnParameters);
			SpawnedActor->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

			UpdateBoxExtent();
		}
	}
}

void ABaseTriggerBox::Destroyed()
{
	Super::Destroyed();
	if (SpawnedActor)
	{
		SpawnedActor->Destroy();
	}
}

#if WITH_EDITOR
void ABaseTriggerBox::PostEditImport()
{
	Super::PostEditImport();

	// Editor에서 Actor를 복사하는 시점에
	// 어디선가 원본으로부터 대상에 변수를 바꾸고 있을 것이다.
	// Actor를 Ctrl+C Ctrl+V를 하면 내부적으로 클립보트에 지정된 포멧의 Text를 만들고
	// 이를 Engine 내부에서 문자열을 파싱해서 복사를 하고 있다.

	// 1차적으로 CDO로 부터 Actor를 하나 만들고
	// 복사된 Text를 통해서 복원하는 과정을 거치고 있다.

	// 값을 복사하고 PostEditImport가 호출 된다.
	// 복사 발생시 2번 호출 되는 것을 확인.
	// 따라서 2번 다 SpawnedActor를 nullptr로 초기화 해 버리면,
	// PostEditImport 이후 OnConstruction이 호출 되는데,
	// 총 2번의 SpawnedActor가 생성되는 문제가 있다.
	// 그래서 SpawnedActor의 Owner가 this가 아닐 때만 SpawnedActor를 초기화 했다.
	if (SpawnedActor->GetOwner() != this)
	{
		SpawnedActor = nullptr;
	}
}
#endif

void ABaseTriggerBox::UpdateBoxExtent()
{
	if (UBoxComponent* BoxComponent = Cast<UBoxComponent>(GetCollisionComponent()))
	{
		UStaticMeshComponent* StaticMeshComponent = SpawnedActor->GetComponentByClass<UStaticMeshComponent>();
		if (StaticMeshComponent)
		{
			if (UStaticMesh* StaticMesh = StaticMeshComponent->GetStaticMesh())
			{
				const FBoxSphereBounds BoxSphereBounds = StaticMesh->GetBounds();
				const FVector Scale3D = StaticMeshComponent->GetRelativeScale3D();
				const FVector NewBoxExtent = BoxSphereBounds.BoxExtent * Scale3D;
				BoxComponent->InitBoxExtent(NewBoxExtent);

				const FVector NewLocation = -BoxSphereBounds.Origin;
				StaticMeshComponent->SetRelativeLocation(NewLocation);
			}
			else { ensure(false); }
		}
		else { ensure(false); }
	}
	else { ensure(false); }

	if (UBoxComponent* BoxComponent = Cast<UBoxComponent>(ActiveCollisionComponent))
	{
		UBoxComponent* RootBoxComponent = Cast<UBoxComponent>(GetCollisionComponent());
		if (RootBoxComponent)
		{
			// 나의 박스 크기가 CDO와 같으면 (내가 수치를 바꾸지 않았다면) 크기를 변경한다.
			const FVector BoxExtent = BoxComponent->GetUnscaledBoxExtent();
			const FVector CDOBoxExtent = GetDefault<UBoxComponent>()->GetUnscaledBoxExtent();
			if (BoxExtent.Equals(CDOBoxExtent))
			{
				const FVector TargetExtent = RootBoxComponent->GetUnscaledBoxExtent() * 5.f;
				BoxComponent->InitBoxExtent(RootBoxComponent->GetUnscaledBoxExtent() * 5.f);
			}
		}
		else { ensure(false); }
	}
	else { ensure(false); }
}

void ABaseTriggerBox::OnActivate(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!SpawnedActor) { return; }

	ITriggerInterface::Execute_OnActive(SpawnedActor, OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void ABaseTriggerBox::OnDeactivate(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!SpawnedActor) { return; }

	ITriggerInterface::Execute_OnDeactive(SpawnedActor, OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}

void ABaseTriggerBox::OnTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!SpawnedActor) { return; }

	ITriggerInterface::Execute_OnTrigger(SpawnedActor, OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}