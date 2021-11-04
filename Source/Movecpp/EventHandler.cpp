#include "MainCharacter.h"

// Function goes here for event triggering
void AMainCharacter::PromptPlayer()
{
	EventPrompt->SetVisibility(true);
	EventPrompt->SetSpriteColor(FLinearColor(1.0, 1.0, 1.0, 1.0));

	// Allow dialogue popup to trigger if E is pressed
}

void AMainCharacter::UnpromptPlayer()
{
	EventPrompt->SetVisibility(false);
	EventPrompt->SetSpriteColor(FLinearColor(1.0, 1.0, 1.0, 0.0));
}

