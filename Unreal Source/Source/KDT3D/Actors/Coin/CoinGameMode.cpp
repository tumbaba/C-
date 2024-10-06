// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Coin/CoinGameMode.h"
#include "Actors/PlayerController/BasicPlayerController.h"
#include "Actors/Coin/CoinGameState.h"
#include "Actors/Coin/CoinHUD.h"

ACoinGameMode::ACoinGameMode()
{
	GameStateClass = ACoinGameState::StaticClass();
	PlayerControllerClass = ABasicPlayerController::StaticClass();
	HUDClass = ACoinHUD::StaticClass();
	{
		static ConstructorHelpers::FClassFinder<APawn> ClassFinder(TEXT("/Script/Engine.Blueprint'/Game/Blueprint/Character/BP_BasicCharacter.BP_BasicCharacter_C'"));
		check(ClassFinder.Class);
		DefaultPawnClass = ClassFinder.Class;
	}
}