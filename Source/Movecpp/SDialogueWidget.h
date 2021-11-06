// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

/**
 * 
 */
class SDialogueWidget : public SCompoundWidget
{	
public:
	
	SLATE_BEGIN_ARGS(SDialogueWidget) {}
	
	SLATE_ARGUMENT(TWeakObjectPtr<class AOverallHUD>, OwningHUD)
	
	SLATE_END_ARGS()

	// Construction Function
	void Construct(const FArguments& InArgs);

	// HUD that creates this widget
	TWeakObjectPtr<class AOverallHUD> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; };

	// Backdrop Data
	UTexture2D* BackdropTexture;

	// Portrait Data
	UTexture2D* CitanTexture;

};
