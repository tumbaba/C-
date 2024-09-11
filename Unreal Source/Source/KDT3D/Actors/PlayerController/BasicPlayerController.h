// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/DataAsset.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "BasicPlayerController.generated.h"

UCLASS()
class KDT3D_API UBasicPlayerControllerDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	// * 내부에서 해당 InputAction으로 등록된 이름을 사용하고 있습니다.
	// * IA_Move : 이동
	// * IA_LookMouse : Camera 회전
	// * IA_Crouch : Crouch
	// * IA_Jump : Jump
	UPROPERTY(EditAnywhere, Category = "Input|InputMappingContext")
	UInputMappingContext* IMC = nullptr;

	const UInputAction* GetInputActionFromName(const FName& InName)
	{
		const TArray<FEnhancedActionKeyMapping>& Mappings = IMC->GetMappings();
		for (auto& It : Mappings)
		{
			if (It.Action->GetFName() == InName)
			{
				return It.Action.Get();
			}
		}

		return nullptr;
	}
};

UCLASS()
class KDT3D_API ABasicPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABasicPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

protected:
	void OnMove(const FInputActionValue& InputActionValue);
	void OnLook(const FInputActionValue& InputActionValue);
	void OnCrouch(const FInputActionValue& InputActionValue);
	void OnUnCrouch(const FInputActionValue& InputActionValue);
	void OnJump(const FInputActionValue& InputActionValue);

protected:
	UPROPERTY()
	UBasicPlayerControllerDataAsset* BasicPlayerControllerDataAsset;
};
