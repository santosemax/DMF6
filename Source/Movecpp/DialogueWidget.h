// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogueWidget.generated.h"

/**
 * 
 */
UCLASS()
class MOVECPP_API UDialogueWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PersonLabel;

	UPROPERTY(meta = (BindWidget))
	class UButton* NextButton;

	void NativeConstruct() override;
	
};
