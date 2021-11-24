// Copyright Epic Games, Inc. All Rights Reserved.

#include "CsvReader.h"
#include "Modules/ModuleManager.h"
//#include "Log"


DEFINE_LOG_CATEGORY(CsvReader);

#define LOCTEXT_NAMESPACE "FCsvReader"

void FCsvReader::StartupModule()
{
	UE_LOG(CsvReader, Warning, TEXT("Csv Reader module has started!"));
}

void FCsvReader::ShutdownModule()
{
	UE_LOG(CsvReader, Warning, TEXT("Csv Reader module has shut down"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FDefaultGameModuleImpl, CsvReader);