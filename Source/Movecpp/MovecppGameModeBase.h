// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MovecppGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MOVECPP_API AMovecppGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	// Creating the Dialogue Widget
	UPROPERTY(EditAnywhere, Category = "Class Types")
	TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
	class UDialogueWidget* DialogueWidget;

	virtual void BeginPlay() override;

};
