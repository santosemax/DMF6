#include "MainCharacter.h"

// These are to help with Debugging
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, text)
#define printf(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

// Box Collider On Overlap Begin
void AMainCharacter::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	eventPossible = true;
	
	// If other actor is overlapping (excluding itself)
	if (OtherActor && (OtherActor != this))
	{
		eventPossible = true;
		
		printf("Overlapped Actor = %s", *OtherActor->GetName());

		PromptPlayer();
	}
}
// Box Collider On Overlap End
void AMainCharacter::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// If other actor is overlapping (excluding itself)
	if (OtherActor && (OtherActor != this))
	{
		eventPossible = false;
		
		printf("Overlapped with %s has ended", *OtherActor->GetName());

		UnpromptPlayer();
	}
}


// Show Event Indicator
void AMainCharacter::PromptPlayer()
{
	EventPrompt->SetVisibility(true);
	EventPrompt->SetSpriteColor(FLinearColor(1.0, 1.0, 1.0, 1.0));
}
// Hide Event Indicator
void AMainCharacter::UnpromptPlayer()
{
	EventPrompt->SetVisibility(false);
	EventPrompt->SetSpriteColor(FLinearColor(1.0, 1.0, 1.0, 0.0));
}



