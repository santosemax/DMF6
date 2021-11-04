// Fill out your copyright notice in the Description page of Project Settings.


#include "SDialogueWidget.h"

#include <ios>

#include "OverallHUD.h"
#include "GameFramework/PlayerController.h"

#define LOCTEXT_NAMESPACE "DialogueBox"

void SDialogueWidget::Construct(const FArguments& InArgs)
{
	// Cast reference to OwningHUD
	OwningHUD = InArgs._OwningHUD;

	// -- CREATE WIDGET -----------------------------------------
	const FMargin ContentPadding = FMargin(250.f, 50.f);
	
	const FText PersonLabel = LOCTEXT("PersonLabel", "Project Anima Demo (Dialogue)");
	const FText BodyText = LOCTEXT("BodyText", "This is a test Slate Widget");

	// Font Stuff
	FSlateFontInfo BodyTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	BodyTextStyle.Size = 15.f;
	FSlateFontInfo PersonLabelStyle = BodyTextStyle;
	PersonLabelStyle.Size =  20.f;

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
						.ColorAndOpacity(FColor::Blue)
					]
					.MaxWidth(225.f)
					
					// Text
					+ SHorizontalBox::Slot()
					[
						SNew(SVerticalBox)
						
						// Person Label
						+ SVerticalBox::Slot()
						[
							SNew(STextBlock)
							.Text(PersonLabel)
							.Font(PersonLabelStyle)
							.Justification(ETextJustify::Left)
						]
						.VAlign(VAlign_Top)
						.HAlign(HAlign_Left)
						.Padding(50)
					
						// Body Text
						+ SVerticalBox::Slot()
						[
							SNew(STextBlock)
							.Text(BodyText)
							.Font(BodyTextStyle)
							.Justification(ETextJustify::Left)
						]
						.VAlign(VAlign_Top)
						.Padding(50)
					]
				]
			]
		];
    	
}



#undef LOCTEXT_NAMESPACE