// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PaperCharacter.h"
#include "PaperFlipbook.h"
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
	class UPaperFlipbook* CharacterAnimation;


public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// Movement Inputs
	void MoveForward(float Value);
	void MoveRight(float Value);

	// Animations/Flipbooks
	UPaperFlipbook* IdleForwardAnim;
	UPaperFlipbook* RunningForwardAnim;
	UPaperFlipbook* IdleBackwardAnim;
	UPaperFlipbook* RunningBackwardAnim;
	UPaperFlipbook* IdleLeftAnim;
	UPaperFlipbook* RunningLeftAnim;
	UPaperFlipbook* IdleRightAnim;
	UPaperFlipbook* RunningRightAnim;

	// Animation Controller Function
	void AnimationSetup();
	UPaperFlipbook* AnimationControl(FVector relativeVelocity);

	// Gettings Current Velocity
	FVector direction;
	FVector relVelocity;

	// Reading Direction Character is Facing
	bool facingForward;
	bool facingBackward;
	bool facingLeft;
	bool facingRight;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
