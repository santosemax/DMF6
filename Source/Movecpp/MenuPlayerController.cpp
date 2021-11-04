// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"
#include "OverallHUD.h"

AMenuPlayerController::AMenuPlayerController()
{
}

void AMenuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputComponent)
	{
		InputComponent->BindAction("OpenMenu", IE_Pressed, this, &AMenuPlayerController::OpenMenu);
	}
}

void AMenuPlayerController::OpenMenu()
{
	if (AOverallHUD* DialogueHUD = Cast<AOverallHUD>(GetHUD()))
	{
		DialogueHUD->ShowMenu();
	}
}
