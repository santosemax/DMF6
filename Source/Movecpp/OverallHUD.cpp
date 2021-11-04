// Fill out your copyright notice in the Description page of Project Settings.


#include "OverallHUD.h"

#include "SDialogueWidget.h"
#include "SPauseWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

void AOverallHUD::BeginPlay()
{
	Super::BeginPlay();

	//ShowMenu();   // Debug Line for Pause Menu Testing
}

// Show Pause Menu
void AOverallHUD::ShowMenu()
{
	if(GEngine && GEngine->GameViewport)
	{

		PauseWidget = SNew(SPauseWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(PauseWidgetContainer, SWeakWidget).PossiblyNullContent(PauseWidget.ToSharedRef()));

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}
// Hide Pause Menu
void AOverallHUD::RemoveMenu()
{
	if (GEngine && GEngine->GameViewport && PauseWidget.IsValid() && PauseWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(PauseWidgetContainer.ToSharedRef());

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}

// Show Dialogue Box
void AOverallHUD::ShowDialogue()
{
	if(GEngine && GEngine->GameViewport)
    	{
    		DialogueWidget = SNew(SDialogueWidget).OwningHUD(this);
    		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(DialogueWidgetContainer, SWeakWidget).PossiblyNullContent(DialogueWidget.ToSharedRef()));
    
    		if (PlayerOwner)
    		{
    			PlayerOwner->bShowMouseCursor = true;
    			PlayerOwner->SetInputMode(FInputModeUIOnly());
    		}
    	}
}

// Remove Dialogue Box
void AOverallHUD::RemoveDialogue()
{
	if (GEngine && GEngine->GameViewport && DialogueWidget.IsValid() && DialogueWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(PauseWidgetContainer.ToSharedRef());

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}
