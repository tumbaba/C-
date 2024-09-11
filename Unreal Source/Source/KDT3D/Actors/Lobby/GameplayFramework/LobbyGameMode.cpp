// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Lobby/GameplayFramework/LobbyGameMode.h"
#include "Actors/PlayerController/BasicPlayerController.h"
#include "LobbyCharacter.h"

ALobbyGameMode::ALobbyGameMode()
{
	PlayerControllerClass = ABasicPlayerController::StaticClass();
	DefaultPawnClass = ALobbyCharacter::StaticClass();
}