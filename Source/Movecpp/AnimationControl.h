#pragma once

#include "PaperCharacter.h"
#include "PaperFlipbook.h"


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
void AnimationControl(FVector relativeVelocity);

// Reading Direction Character is Facing
bool facingForward;
bool facingBackward;
bool facingLeft;
bool facingRight;


