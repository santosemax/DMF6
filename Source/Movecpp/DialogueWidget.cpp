// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueWidget.h"
#include <Components/Button.h>
#include <Components/TextBlock.h>

void UDialogueWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Call function once widget is constructed
	PersonLabel->SetText(FText::FromString("Citan"));
}
