#include "MainCharacter.h"
#include "PaperFlipbookComponent.h"
#include "PaperCharacter.h"
#include "PaperFlipbook.h"


// Initialize Animations/Flipbooks
void AMainCharacter::AnimationSetup()
{
	// ANIMATIONS/FLIPBOOKS
	// Create + Attaching Flipbook Component
	CharacterComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("SpriteAnim"));
	CharacterComponent->SetupAttachment(RootComponent);

	// Setting up Animation Variables
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> IdleForwardAsset;      // Forward
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> WalkingForwardAsset;   
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> WalkingRightForwardAsset;
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> WalkingLeftForwardAsset;
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> IdleBackwardAsset;     // Backward
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> WalkingBackwardAsset; 
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> WalkingRightBackwardAsset; 
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> WalkingLeftBackwardAsset; 
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> IdleLeftAsset;         // Left
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> WalkingLeftAsset;
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> IdleRightAsset;        // Right
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> WalkingRightAsset;
		FConstructorStatics()
			// Forward
			:IdleForwardAsset(TEXT("PaperFlipbook'/Game/Flipbooks/Fei/IdleForward.IdleForward'")),
			WalkingForwardAsset(TEXT("PaperFlipbook'/Game/Flipbooks/Fei/WalkForward.WalkForward'")),
			WalkingRightForwardAsset(TEXT("PaperFlipbook'/Game/Flipbooks/Fei/WalkRightForward.WalkRightForward'")),
			WalkingLeftForwardAsset(TEXT("PaperFlipbook'/Game/Flipbooks/Fei/WalkLeftForward.WalkLeftForward'")),
			// Backward
			IdleBackwardAsset(TEXT("PaperFlipbook'/Game/Flipbooks/Fei/IdleBackward.IdleBackward'")),
			WalkingBackwardAsset(TEXT("PaperFlipbook'/Game/Flipbooks/Fei/WalkBackward.WalkBackward'")),
			WalkingRightBackwardAsset(TEXT("PaperFlipbook'/Game/Flipbooks/Fei/WalkRightBackward.WalkRightBackward'")),
			WalkingLeftBackwardAsset(TEXT("PaperFlipbook'/Game/Flipbooks/Fei/WalkLeftBackward.WalkLeftBackward'")),
			// Left
			IdleLeftAsset(TEXT("PaperFlipbook'/Game/Flipbooks/Fei/IdleLeft.IdleLeft'")),
			WalkingLeftAsset(TEXT("PaperFlipbook'/Game/Flipbooks/Fei/WalkLeft.WalkLeft'")),
			// Right
			IdleRightAsset(TEXT("PaperFlipbook'/Game/Flipbooks/Fei/IdleRight.IdleRight'")),
			WalkingRightAsset(TEXT("PaperFlipbook'/Game/Flipbooks/Fei/WalkRight.WalkRight'"))

		{
		}
	};
	static FConstructorStatics ConstructorStatics;
	IdleForwardAnim = ConstructorStatics.IdleForwardAsset.Get();                // Forward
	WalkingForwardAnim = ConstructorStatics.WalkingForwardAsset.Get();
	WalkingRightForwardAnim = ConstructorStatics.WalkingRightForwardAsset.Get();
	WalkingLeftForwardAnim = ConstructorStatics.WalkingLeftForwardAsset.Get();
	IdleBackwardAnim = ConstructorStatics.IdleBackwardAsset.Get();              // Backward
	WalkingBackwardAnim = ConstructorStatics.WalkingBackwardAsset.Get();
	WalkingRightBackwardAnim = ConstructorStatics.WalkingRightBackwardAsset.Get();
	WalkingLeftBackwardAnim = ConstructorStatics.WalkingLeftBackwardAsset.Get();
	IdleLeftAnim = ConstructorStatics.IdleLeftAsset.Get();                      // Left
	WalkingLeftAnim = ConstructorStatics.WalkingLeftAsset.Get();
	IdleRightAnim = ConstructorStatics.IdleRightAsset.Get();                    // Right
	WalkingRightAnim = ConstructorStatics.WalkingRightAsset.Get();
	
}

// Animation Controller
UPaperFlipbook* AMainCharacter::AnimationControl(FVector relativeVelocity)
{
	UPaperFlipbook* DesiredAnimation = IdleForwardAnim;

	const float moveHoriz = relativeVelocity.Y;
	const float moveVert = relativeVelocity.X;

	// Idling
	if (moveHoriz == 0 && moveVert == 0)
	{
		if (facingForward)
		{
			DesiredAnimation = IdleForwardAnim;
		}
		else if (facingBackward)
		{
			DesiredAnimation = IdleBackwardAnim;
		}
		else if (facingLeft)
		{
			DesiredAnimation = IdleLeftAnim;
		}
		else if (facingRight)
		{
			DesiredAnimation = IdleRightAnim;
		}
	}

	// EIGHT DIRECTIONS
	// Moving Forwards
	if (moveHoriz == 0 && moveVert == -1)
	{
		DesiredAnimation = WalkingForwardAnim;
		facingForward = true;
		facingLeft = false, facingBackward = false, facingRight = false;
	}
	// Moving Right Forwards
	if (moveHoriz == 1 && moveVert == -1)
	{
		DesiredAnimation = WalkingRightForwardAnim;
		facingForward = true;
		facingLeft = false, facingBackward = false, facingRight = false;
	}
	// Moving Left Forwards
	if (moveHoriz == -1 && moveVert == -1)
	{
		DesiredAnimation = WalkingLeftForwardAnim;
		facingForward = true;
		facingLeft = false, facingBackward = false, facingRight = false;
	}

	// Moving Backwards
	if (moveHoriz == 0 && moveVert == 1)
	{
		DesiredAnimation = WalkingBackwardAnim;
		facingBackward = true;
		facingLeft = false, facingRight = false, facingForward = false;

	}
	// Moving Right Backward
	if (moveHoriz == 1 && moveVert == 1)
	{
		DesiredAnimation = WalkingRightBackwardAnim;
		facingBackward = true;
		facingLeft = false, facingRight = false, facingForward = false;
	}
	// Moving Left Backward
	if (moveHoriz == -1 && moveVert == 1)
	{
		DesiredAnimation = WalkingLeftBackwardAnim;
		facingBackward = true;
		facingLeft = false, facingRight = false, facingForward = false;
	}

	// Moving Left
	if (moveHoriz == -1 && moveVert == 0)
	{
		DesiredAnimation = WalkingLeftAnim;
		facingLeft = true;
		facingBackward = false, facingRight = false, facingForward = false;
	}
	// Moving Right
	if (moveHoriz == 1 && moveVert == 0)
	{
		DesiredAnimation = WalkingRightAnim;
		facingRight = true;
		facingBackward = false, facingLeft = false, facingForward = false;
	}

	return DesiredAnimation;

}