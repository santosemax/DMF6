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
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> IdleForwardAsset;
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> RunningForwardAsset;
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> IdleBackwardAsset;
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> RunningBackwardAsset;
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> IdleLeftAsset;
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> RunningLeftAsset;
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> IdleRightAsset;
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> RunningRightAsset;
		FConstructorStatics()
			// Forward
			:IdleForwardAsset(TEXT("PaperFlipbook'/Game/Flipbooks/ForwardIdle.ForwardIdle'")),
			RunningForwardAsset(TEXT("PaperFlipbook'/Game/Flipbooks/RunForward.RunForward'")),
			// Backward
			IdleBackwardAsset(TEXT("PaperFlipbook'/Game/Flipbooks/BackwardIdle.BackwardIdle'")),
			RunningBackwardAsset(TEXT("PaperFlipbook'/Game/Flipbooks/RunBackward.RunBackward'")),
			// Left
			IdleLeftAsset(TEXT("PaperFlipbook'/Game/Flipbooks/LeftIdle.LeftIdle'")),
			RunningLeftAsset(TEXT("PaperFlipbook'/Game/Flipbooks/RunLeft.RunLeft'")),
			// Right
			IdleRightAsset(TEXT("PaperFlipbook'/Game/Flipbooks/IdleRight.IdleRight'")),
			RunningRightAsset(TEXT("PaperFlipbook'/Game/Flipbooks/RunRight.RunRight'"))

		{
		}
	};
	static FConstructorStatics ConstructorStatics;
	IdleForwardAnim = ConstructorStatics.IdleForwardAsset.Get();
	RunningForwardAnim = ConstructorStatics.RunningForwardAsset.Get();
	IdleBackwardAnim = ConstructorStatics.IdleBackwardAsset.Get();
	RunningBackwardAnim = ConstructorStatics.RunningBackwardAsset.Get();
	IdleLeftAnim = ConstructorStatics.IdleLeftAsset.Get();
	RunningLeftAnim = ConstructorStatics.RunningLeftAsset.Get();
	IdleRightAnim = ConstructorStatics.IdleRightAsset.Get();
	RunningRightAnim = ConstructorStatics.RunningRightAsset.Get();
	
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
		DesiredAnimation = RunningForwardAnim;
		facingForward = true;
		facingLeft = false, facingBackward = false, facingRight = false;
	}
	// Moving Right Forwards
	if (moveHoriz == 1 && moveVert == -1)
	{
		DesiredAnimation = RunningForwardAnim;
		facingForward = true;
		facingLeft = false, facingBackward = false, facingRight = false;
	}
	// Moving Left Forwards
	if (moveHoriz == -1 && moveVert == -1)
	{
		DesiredAnimation = RunningForwardAnim;
		facingForward = true;
		facingLeft = false, facingBackward = false, facingRight = false;
	}

	// Moving Backwards
	if (moveHoriz == 0 && moveVert == 1)
	{
		DesiredAnimation = RunningBackwardAnim;
		facingBackward = true;
		facingLeft = false, facingRight = false, facingForward = false;

	}
	// Moving Right Backward
	if (moveHoriz == 1 && moveVert == 1)
	{
		DesiredAnimation = RunningBackwardAnim;
		facingBackward = true;
		facingLeft = false, facingRight = false, facingForward = false;
	}
	// Moving Left Backward
	if (moveHoriz == -1 && moveVert == 1)
	{
		DesiredAnimation = RunningBackwardAnim;
		facingBackward = true;
		facingLeft = false, facingRight = false, facingForward = false;
	}

	// Moving Left
	if (moveHoriz == -1 && moveVert == 0)
	{
		DesiredAnimation = RunningLeftAnim;
		facingLeft = true;
		facingBackward = false, facingRight = false, facingForward = false;
	}
	// Moving Right
	if (moveHoriz == 1 && moveVert == 0)
	{
		DesiredAnimation = RunningRightAnim;
		facingRight = true;
		facingBackward = false, facingLeft = false, facingForward = false;
	}

	return DesiredAnimation;

}