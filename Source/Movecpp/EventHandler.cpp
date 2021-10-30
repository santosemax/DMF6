#include "MainCharacter.h"
#include "DialogueWidget.h"
#include "GameFramework/PlayerController.h"
#include "Engine/EngineBaseTypes.h"
#include "PaperFlipbookComponent.h"
#include "PaperCharacter.h"
#include "PaperFlipbook.h"

// Function goes here for event triggering
void AMainCharacter::PromptPlayer()
{
	EventPrompt->SetVisibility(true);
	EventPrompt->SetSpriteColor(FLinearColor(1.0, 1.0, 1.0, 1.0));
	eventCanTrigger = true;

	// Allow dialogue popup to trigger if E is pressed
}

void AMainCharacter::UnpromptPlayer()
{
	EventPrompt->SetVisibility(false);
	EventPrompt->SetSpriteColor(FLinearColor(1.0, 1.0, 1.0, 0.0));
	eventCanTrigger = false;
}

void AMainCharacter::EventActivated()
{

	if (eventCanTrigger)
	{
		// Check if Dialogue (Load Textbox w/ Custom Dialogue Object)
	
		// Check if Environmental
	
	}
}
