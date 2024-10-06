// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/TPS/TPSPlayerController.h"
#include "Components/SoftWheelSpringArmComponent.h"

ATPSPlayerController::ATPSPlayerController()
{
	{
		static ConstructorHelpers::FObjectFinder<UInputMappingContext> Asset
		{ TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Blueprint/TPSMap/Input/TPS/IMC_TPS.IMC_TPS'") };
		check(Asset.Object);

		IMC_TPS = Asset.Object;
	}

	bZoomWheel = false;
}

void ATPSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SpringArm = GetPawn()->GetComponentByClass<USoftWheelSpringArmComponent>();
	check(SpringArm);
	SpringArm->SetMinMaxTargetArmLength(160.f, 260.f);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	Subsystem->AddMappingContext(IMC_TPS, 0);
}

void ATPSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	ensure(EnhancedInputComponent);

	if (const UInputAction* InputAction = FUtils::GetInputActionFromName(IMC_TPS, TEXT("IA_Zoom")))
	{
		EnhancedInputComponent->BindAction(InputAction, ETriggerEvent::Started, this, &ThisClass::OnZoomIn);
		EnhancedInputComponent->BindAction(InputAction, ETriggerEvent::Completed, this, &ThisClass::OnZoomOut);
	}
	else
	{
		ensureMsgf(false, TEXT("IA_Move is disabled"));
	}
}

void ATPSPlayerController::OnZoomIn(const FInputActionValue& InputActionValue)
{
	SpringArm->SetDesiredZoom(160.f);
}

void ATPSPlayerController::OnZoomOut(const FInputActionValue& InputActionValue)
{
	SpringArm->SetDesiredZoom(260.f);
}
