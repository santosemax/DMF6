// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimaGameModeBase.h"
#include "MenuPlayerController.h"
#include "OverallHUD.h"

AAnimaGameModeBase::AAnimaGameModeBase()
{
	PlayerControllerClass = AMenuPlayerController::StaticClass();
	HUDClass = AOverallHUD::StaticClass();
}
