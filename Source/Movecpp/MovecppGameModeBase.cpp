// Copyright Epic Games, Inc. All Rights Reserved.


#include "MovecppGameModeBase.h"
#include "MenuPlayerController.h"
#include "OverallHUD.h"

AMovecppGameModeBase::AMovecppGameModeBase()
{
	PlayerControllerClass = AMenuPlayerController::StaticClass();
	HUDClass = AOverallHUD::StaticClass();
}

