// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MainCharacter.h"
#include "CitanTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class MOVECPP_API ACitanTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	

protected:
	// Called when game starts/object spawned
	virtual void BeginPlay() override;

public:

	AMainCharacter* MainCharacter;

	// Constructor sets default values for this actor's properties
	ACitanTriggerBox();

	// Overlap begin function declaration
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// declare overlap end function
	UFUNCTION()
	void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

};
