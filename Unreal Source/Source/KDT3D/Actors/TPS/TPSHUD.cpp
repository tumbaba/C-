// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/TPS/TPSHUD.h"
#include "Actors/TPS/TPSHUDUserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "TPSPlayerController.h"

ATPSHUD::ATPSHUD()
{
	{
		static ConstructorHelpers::FObjectFinder<UInputMappingContext> Asset
		{ TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Blueprint/TPSMap/Input/Item/IMC_Item.IMC_Item'") };
		check(Asset.Object);

		IMC_Item = Asset.Object;
	}
}

void ATPSHUD::AddDroppedItem(ADroppedItem* NewItem)
{
	Widget->AddDroppedItem(NewItem);
}

void ATPSHUD::RemoveDroppedItem(ADroppedItem* NewItem)
{
	Widget->RemoveDroppedItem(NewItem);
}

void ATPSHUD::OnPickupItem(const FInputActionValue& InputActionValue)
{
	if (OverlappedDroppedItems.IsEmpty()) { return; }

	ADroppedItem* DroppedItem = static_cast<ADroppedItem*>(*OverlappedDroppedItems.begin());
	DroppedItem->UseItem(PlayerController);
	DroppedItem->Destroy();
}

void ATPSHUD::BeginPlay()
{
	Super::BeginPlay();

	UClass* WidgetClass = LoadClass<UTPSHUDUserWidget>(nullptr,
		TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/TPSMap/UI_TPS.UI_TPS_C'"));
	check(WidgetClass);
	Widget = CreateWidget<UTPSHUDUserWidget>(GetWorld(), WidgetClass);
	Widget->AddToViewport();

	PlayerController = Cast<ATPSPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	check(PlayerController);

	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		Subsystem->AddMappingContext(IMC_Item, 0);
		EnableInput(PlayerController);
		UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
		ensure(EnhancedInputComponent);
		if (const UInputAction* InputAction = FUtils::GetInputActionFromName(IMC_Item, TEXT("IA_PickupItem")))
		{
			EnhancedInputComponent->BindAction(InputAction, ETriggerEvent::Started, this, &ThisClass::OnPickupItem);
		}
	}
}

void ATPSHUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (APawn* Pawn = PlayerController->GetPawn())
	{
		TArray<AActor*> Temp;
		Pawn->GetOverlappingActors(Temp, ADroppedItem::StaticClass());

		if (Temp != OverlappedDroppedItems)
		{
			for (AActor* It : OverlappedDroppedItems)
			{
				RemoveDroppedItem(static_cast<ADroppedItem*>(It));
			}
			OverlappedDroppedItems = MoveTemp(Temp);

			for (AActor* It : OverlappedDroppedItems)
			{
				AddDroppedItem(static_cast<ADroppedItem*>(It));
			}
		}
	}
}
