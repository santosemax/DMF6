// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCharacter.h"
#include "GameFramework/PlayerController.h"
#include "MenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MOVECPP_API AMenuPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	//AMainCharacter* MainCharacter;

	// Use TSharedPtr to access main character (Idk why I can't use
	// a normal ptr but w/e this works
	AMainCharacter* MainCharacter;

protected:
	
	AMenuPlayerController();
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
	void OpenPauseMenu();
	void OpenDialogue();
	
};
