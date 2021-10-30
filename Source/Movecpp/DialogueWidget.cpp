// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueWidget.h"
#include <Components/Button.h>
#include <Components/TextBlock.h>

bool UDialogueWidget::Initialize()
{
	Super::Initialize();

	return true;
}

void UDialogueWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Call function once widget is constructed
	PersonLabel->SetText(FText::FromString("Citan"));

	BodyContent->SetText(FText::FromString("My name is Citan. I can't say anything else about myself since Filippo wants to play Xenogears lol."));
}
