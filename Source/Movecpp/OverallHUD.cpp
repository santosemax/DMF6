// Fill out your copyright notice in the Description page of Project Settings.


#include "OverallHUD.h"
#include "SDialogueWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

void AOverallHUD::BeginPlay()
{
	Super::BeginPlay();

	//ShowMenu();
}

void AOverallHUD::ShowMenu()
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

void AOverallHUD::RemoveMenu()
{
	if (GEngine && GEngine->GameViewport && DialogueWidget.IsValid() && DialogueWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(DialogueWidgetContainer.ToSharedRef());

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}
