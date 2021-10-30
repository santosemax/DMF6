// Copyright Epic Games, Inc. All Rights Reserved.


#include "MovecppGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "DialogueWidget.h"

void AMovecppGameModeBase::BeginPlay()
{
	// Getting Widget
	if (IsValid(WidgetClass))
	{
		DialogueWidget = Cast<UDialogueWidget>(CreateWidget(GetWorld(), WidgetClass));

		DialogueWidget->AddToViewport();
	}
}
