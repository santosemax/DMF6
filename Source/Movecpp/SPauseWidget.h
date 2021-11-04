// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

/**
 * 
 */
class SPauseWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPauseWidget) {}
	
	SLATE_ARGUMENT(TWeakObjectPtr<class AOverallHUD>, OwningHUD)
	
	SLATE_END_ARGS()
	
	// Every widget needs a construction function
	void Construct(const FArguments& InArgs);

	FReply OnPlayClicked() const;
	//FReply OnQuitClicked() const;

	// HUD that created this widget
	TWeakObjectPtr<class AOverallHUD> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; };
};
