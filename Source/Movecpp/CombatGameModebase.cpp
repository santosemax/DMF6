// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatGameModebase.h"

#include "MenuPlayerController.h"

ACombatGameModebase::ACombatGameModebase()
{
	PlayerControllerClass = AMenuPlayerController::StaticClass();
}
