// Fill out your copyright notice in the Description page of Project Settings.


#include "OverallHUD.h"
#include "SPauseWidget.h"
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

		PauseWidget = SNew(SPauseWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(PauseWidgetContainer, SWeakWidget).PossiblyNullContent(PauseWidget.ToSharedRef()));

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}

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
