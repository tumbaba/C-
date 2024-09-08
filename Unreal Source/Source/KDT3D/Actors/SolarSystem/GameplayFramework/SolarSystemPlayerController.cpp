// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SolarSystem/GameplayFramework/SolarSystemPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "LoadingScreen/AsyncLoadingScreenSubsystem.h"

ASolarSystemPlayerController::ASolarSystemPlayerController()
{
	bShowMouseCursor = true;

	{
		static ConstructorHelpers::FObjectFinder<USolarSystemPlayerControllerDataAsset> Asset{ TEXT("/Script/KDT3D.SolarSystemPlayerControllerDataAsset'/Game/Blueprint/SolarSystem/GameplayFramework/DA_SolarSystemPlayerController.DA_SolarSystemPlayerController'") };
		check(Asset.Object);

		SolarSystemPlayerControllerDataAsset = Asset.Object;
	}
}

void ASolarSystemPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	Subsystem->AddMappingContext(SolarSystemPlayerControllerDataAsset->IMC, 0);
}

void ASolarSystemPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	ensure(EnhancedInputComponent);

	EnhancedInputComponent->BindAction(SolarSystemPlayerControllerDataAsset->IA_Start, ETriggerEvent::Completed, this, &ThisClass::OnStart);
}

void ASolarSystemPlayerController::OnStart(const FInputActionValue& InputActionValue)
{
	// InputActionValue.Get<bool>();

	UAsyncLoadingScreenSubsystem* Subsystem = GetGameInstance()->GetSubsystem<UAsyncLoadingScreenSubsystem>();
	Subsystem->OpenLevelWithLoadingScreen(
		SolarSystemPlayerControllerDataAsset->LevelLodingWidgetClass,
		SolarSystemPlayerControllerDataAsset->NextLevel);

}
