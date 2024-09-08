// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SolarSystem/GamePlayFramework/SolarSystemGameMode.h"
#include "SolarSystemPlayerController.h"

ASolarSystemGameMode::ASolarSystemGameMode()
{
	PlayerControllerClass = ASolarSystemPlayerController::StaticClass();
}