// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicPlayerController.h"
#include "Actors/PlayerCameraManager/BasicPlayerCameraManager.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Character.h"
#include "Components/NoFallCharacterMovementComponent.h"

ABasicPlayerController::ABasicPlayerController()
{
	{
		static ConstructorHelpers::FObjectFinder<UBasicPlayerControllerDataAsset> Asset
		{ TEXT("/Script/KDT3D.BasicPlayerControllerDataAsset'/Game/Blueprint/LobbyMap/GameplayFramework/DA_BasicPlayerController.DA_BasicPlayerController'") };
		check(Asset.Object);

		BasicPlayerControllerDataAsset = Asset.Object;
	}

	PlayerCameraManagerClass = ABasicPlayerCameraManager::StaticClass();
}

void ABasicPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	Subsystem->AddMappingContext(BasicPlayerControllerDataAsset->IMC, 0);
}

void ABasicPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	ensure(EnhancedInputComponent);

	if (const UInputAction* InputAction = BasicPlayerControllerDataAsset->GetInputActionFromName(TEXT("IA_Move")))
	{
		EnhancedInputComponent->BindAction(InputAction, ETriggerEvent::Triggered, this, &ThisClass::OnMove);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("IA_Move is disabled"));
	}

	if (const UInputAction* InputAction = BasicPlayerControllerDataAsset->GetInputActionFromName(TEXT("IA_LookMouse")))
	{
		EnhancedInputComponent->BindAction(InputAction, ETriggerEvent::Triggered, this, &ThisClass::OnLook);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("IA_LookMouse is disabled"));
	}

	if (const UInputAction* InputAction = BasicPlayerControllerDataAsset->GetInputActionFromName(TEXT("IA_Crouch")))
	{
		EnhancedInputComponent->BindAction(InputAction, ETriggerEvent::Triggered, this, &ThisClass::OnCrouch);
		EnhancedInputComponent->BindAction(InputAction, ETriggerEvent::Completed, this, &ThisClass::OnUnCrouch);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("IA_Crouch is disabled"));
	}

	if (const UInputAction* InputAction = BasicPlayerControllerDataAsset->GetInputActionFromName(TEXT("IA_Jump")))
	{
		EnhancedInputComponent->BindAction(InputAction,
			ETriggerEvent::Started, this, &ThisClass::OnJump);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("IA_Jump is disabled"));
	}
}

void ABasicPlayerController::OnMove(const FInputActionValue& InputActionValue)
{
	const FVector2D ActionValue = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = K2_GetActorRotation();
	const FRotator RotationYaw = FRotator(0.0, Rotation.Yaw, 0.0);
	const FVector ForwardVector = UKismetMathLibrary::GetForwardVector(RotationYaw);
	const FVector RightVector = UKismetMathLibrary::GetRightVector(RotationYaw);

	APawn* ControlledPawn = GetPawn();
	ControlledPawn->AddMovementInput(ForwardVector, ActionValue.X);
	ControlledPawn->AddMovementInput(RightVector, ActionValue.Y);
}

void ABasicPlayerController::OnLook(const FInputActionValue& InputActionValue)
{
	const FVector2D ActionValue = InputActionValue.Get<FVector2D>();

	AddYawInput(ActionValue.X);
	AddPitchInput(ActionValue.Y);
}

void ABasicPlayerController::OnCrouch(const FInputActionValue& InputActionValue)
{
	ACharacter* ControlledCharacter = Cast<ACharacter>(GetPawn());
	if (ControlledCharacter->GetMovementComponent()->IsFalling()) { return; }
	ControlledCharacter->Crouch();
}

void ABasicPlayerController::OnUnCrouch(const FInputActionValue& InputActionValue)
{
	ACharacter* ControlledCharacter = Cast<ACharacter>(GetPawn());
	ControlledCharacter->UnCrouch();
}

void ABasicPlayerController::OnJump(const FInputActionValue& InputActionValue)
{
	ACharacter* ControlledCharacter = Cast<ACharacter>(GetPawn());
	ControlledCharacter->Jump();

	if (ControlledCharacter->bIsCrouched)
	{

	}
}
