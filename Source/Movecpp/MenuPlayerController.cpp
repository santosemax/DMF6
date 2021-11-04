// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"
#include "OverallHUD.h"
#include "CitanTriggerBox.h"

AMenuPlayerController::AMenuPlayerController()
{
}

void AMenuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputComponent)
	{
		InputComponent->BindAction("OpenMenu", IE_Pressed, this, &AMenuPlayerController::OpenPauseMenu);
		InputComponent->BindAction("EventAction", IE_Pressed, this, &AMenuPlayerController::OpenDialogue);
	}
}

// Open Pause Menu if Escape is pressed (Shift-Escape for Preview in unreal editor)
void AMenuPlayerController::OpenPauseMenu()
{
	if (AOverallHUD* PauseHUD = Cast<AOverallHUD>(GetHUD()))
	{
		PauseHUD->ShowMenu();
	}
}

void AMenuPlayerController::OpenDialogue()
{
	if (AOverallHUD* DialogueHUD = Cast<AOverallHUD>(GetHUD()))
	{
		DialogueHUD->ShowDialogue();
	}
}

