// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include <Modules/ModuleManager.h>
#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(CsvReader, Log, All);

class FCsvReader : public IModuleInterface
{

public:
	virtual void StartupModule() override;

	virtual void ShutdownModule() override;
};
