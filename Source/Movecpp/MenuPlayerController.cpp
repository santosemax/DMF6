// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"
#include "OverallHUD.h"
#include "Kismet/GameplayStatics.h"
#include "CitanTriggerBox.h"

AMenuPlayerController::AMenuPlayerController()
{
}

// Cast to MainCharacter so we can access eventPossible boolean
void AMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	MainCharacter = Cast<AMainCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
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

// Open Dialogue Box (If an Event is Possible)
void AMenuPlayerController::OpenDialogue()
{
	if (MainCharacter->eventPossible == true)
	{
		if (AOverallHUD* DialogueHUD = Cast<AOverallHUD>(GetHUD()))
		{
			DialogueHUD->ShowDialogue();
		}
	}
	
}

