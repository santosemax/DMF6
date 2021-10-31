// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueWidget.h"
#include "GameFramework/Character.h"
#include "PaperCharacter.h"
#include "PaperFlipbook.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "MainCharacter.generated.h"

UCLASS()
class MOVECPP_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadONly, meta=(AllowPrivateAccess = "true"))
	class USpringArmComponent* BoomArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UPaperFlipbookComponent* CharacterComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UPaperSpriteComponent* EventPrompt;




public:
	// Sets default values for this character's properties
	AMainCharacter();
	
	// Events
	void PromptPlayer();
	void UnpromptPlayer();
	void EventActivated();
	bool eventCanTrigger;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// Movement Inputs
	void MoveForward(float Value);
	void MoveRight(float Value);

	// Animations/Flipbooks
	UPaperFlipbook* IdleForwardAnim;        // Forward
	UPaperFlipbook* WalkingForwardAnim;
	UPaperFlipbook* IdleRightForwardAnim;
	UPaperFlipbook* WalkingRightForwardAnim;
	UPaperFlipbook* IdleLeftForwardAnim;
	UPaperFlipbook* WalkingLeftForwardAnim;
	UPaperFlipbook* IdleBackwardAnim;       // Backward
	UPaperFlipbook* WalkingBackwardAnim;
	UPaperFlipbook* IdleRightBackwardAnim;
	UPaperFlipbook* WalkingRightBackwardAnim;
	UPaperFlipbook* IdleLeftBackwardAnim;
	UPaperFlipbook* WalkingLeftBackwardAnim;
	UPaperFlipbook* IdleLeftAnim;           // Left
	UPaperFlipbook* WalkingLeftAnim;
	UPaperFlipbook* IdleRightAnim;          // Right
	UPaperFlipbook* WalkingRightAnim;

	// Animation Controller Function
	void AnimationSetup();
	UPaperFlipbook* AnimationControl(FVector relativeVelocity);

	// Gettings Current Velocity
	FVector direction;
	FVector relVelocity;

	// Reading Direction Character is Facing
	bool facingForward;
	bool facingRightForward;
	bool facingLeftForward;
	bool facingBackward;
	bool facingRightBackward;
	bool facingLeftBackward;
	bool facingLeft;
	bool facingRight;

	// Dialogue Widget
	class DialogueWidget* DialogueWidget;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
