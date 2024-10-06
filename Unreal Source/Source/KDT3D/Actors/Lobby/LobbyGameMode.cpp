// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "Actors/PlayerController/BasicPlayerController.h"
#include "Actors/Character/BasicCharacter.h"

ALobbyGameMode::ALobbyGameMode()
{
	PlayerControllerClass = ABasicPlayerController::StaticClass();
	DefaultPawnClass = ABasicCharacter::StaticClass();
}