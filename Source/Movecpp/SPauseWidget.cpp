// Fill out your copyright notice in the Description page of Project Settings.


#include "SPauseWidget.h"
#include "OverallHUD.h"
#include "GameFramework/PlayerController.h"

#define LOCTEXT_NAMESPACE "MainMenu"

void SPauseWidget::Construct(const FArguments& InArgs)
{
	// Avoid annoying error message (?)
	bCanSupportFocus = true;

	// Cast reference to OwningHUD
	OwningHUD = InArgs._OwningHUD;
	
	const FMargin ContentPadding = FMargin(500.f, 300.f);
	const FMargin ButtonPadding = FMargin(10.f);
	
	const FText PersonLabel = LOCTEXT("PersonLabel", "Project Anima Demo");
	const FText BodyText = LOCTEXT("BodyText", "This is a test Slate Widget");
	const FText ButtonText = LOCTEXT("ButtonText", "Play Demo");

	// Font Stuff
	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;
	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	TitleTextStyle.Size =  20.f;

	ChildSlot
		[
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
			.VAlign(VAlign_Fill)
			.Padding(ContentPadding)
			[
				SNew(SVerticalBox)

				// Title Text
				+ SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Text(PersonLabel)
					.Font(TitleTextStyle)
					.Justification(ETextJustify::Center)
				]

				// Body Text
				+ SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Text(BodyText)
					.Font(TitleTextStyle)
					.Justification(ETextJustify::Center)
				]
				
				// Next Button
				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)
				[
					SNew(SButton)
					.OnClicked(this, &SPauseWidget::OnPlayClicked)
					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(ButtonText)
						.Justification(ETextJustify::Center)
					]
				]
			]
		];
	
}

FReply SPauseWidget::OnPlayClicked() const
{

	UE_LOG(LogTemp, Warning, TEXT("PLAY CLICKED"));

	if (OwningHUD.IsValid())
	{
		OwningHUD->RemoveMenu();
	}
	
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
