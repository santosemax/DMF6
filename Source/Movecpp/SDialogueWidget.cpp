// Fill out your copyright notice in the Description page of Project Settings.


#include "SDialogueWidget.h"

#include "OverallHUD.h"
#include "GameFramework/PlayerController.h"

#define LOCTEXT_NAMESPACE "DialogueBox"

void SDialogueWidget::Construct(const FArguments& InArgs)
{
	// Cast reference to OwningHUD
	OwningHUD = InArgs._OwningHUD;

	// -- CREATE WIDGET -----------------------------------------
	const FMargin ContentPadding = FMargin(500.f, 50.f);
	
	const FText PersonLabel = LOCTEXT("PersonLabel", "Mr. NPC");
	const FText BodyText = LOCTEXT("BodyText", "This is a test Slate Widget");

	// Backdrop
	BackdropTexture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/UI/TextBoxAssets/Blue_Diag_Box.Blue_Diag_Box'"), NULL, LOAD_None, NULL);
	FSlateImageBrush* UseForBackdrop = new FSlateImageBrush(BackdropTexture, FVector2D(156, 160));
	
	// Portrait Image (TEST EXAMPLE) - 1. Load/Bake Texture 2. Load into Brush
	CitanTexture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/UI/TextBoxAssets/terra-portrait.terra-portrait'"), NULL, LOAD_None, NULL);
	FSlateImageBrush* UseForCitan = new FSlateImageBrush(CitanTexture, FVector2D(156, 160));
	// Font Stuff
	FSlateFontInfo PersonLabelStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	PersonLabelStyle.Size =  25.f;
	FSlateFontInfo BodyTextStyle = PersonLabelStyle;
	BodyTextStyle.Size = 20.f;


	ChildSlot
		[
			SNew(SOverlay)
			// Backdrop
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Bottom)
			.Padding(ContentPadding)
			[
				// Backdrop v2
				SNew(SOverlay)
				+ SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SImage)
					.ColorAndOpacity(FColor::Black)
					//.Image(UseForBackdrop)
				]

				+ SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Bottom)
				[
			
					SNew(SHorizontalBox)
					
					// Portrait Box
					+ SHorizontalBox::Slot()
					[
						SNew(SImage)
						.Image(UseForCitan)
					]
					.MaxWidth(200.f)
					
					// Text
					+ SHorizontalBox::Slot()
					[
						SNew(SVerticalBox)
						
						// Person Label
						+ SVerticalBox::Slot()
						.AutoHeight()
						[
							SNew(STextBlock)
							.Text(PersonLabel)
							.Font(PersonLabelStyle)
							.Margin(FMargin(10.f, 30.f))
							.Justification(ETextJustify::Left)
						]
						.VAlign(VAlign_Top)
						.HAlign(HAlign_Left)
						//.Padding(50)
					
						// Body Text
						+ SVerticalBox::Slot()
						[
							SNew(STextBlock)
							.Text(BodyText)
							.Font(BodyTextStyle)
							.Margin(FMargin(10.f, -30.f))
							.Justification(ETextJustify::Left)
						]
						.VAlign(VAlign_Top)
						//.Padding(50)
					]
				]
			]
		];
    	
}



#undef LOCTEXT_NAMESPACE