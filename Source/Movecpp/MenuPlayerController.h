// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CitanTriggerBox.h"
#include "GameFramework/PlayerController.h"
#include "MenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MOVECPP_API AMenuPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	
	AMenuPlayerController();
	virtual void SetupInputComponent() override;
	
	void OpenPauseMenu();
	void OpenDialogue();
	
};
