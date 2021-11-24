// Fill out your copyright notice in the Description page of Project Settings.


#include "StatsManager.h"
#include <Misc/FileHelper.h>
#include <Misc/Paths.h>
#include <HAL/PlatformFilemanager.h>
#include "StatsStruct.h"

	// Sets default values
AStatsManager::AStatsManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStatsManager::BeginPlay()
{
	Super::BeginPlay();

	FString Str;
	TArray<FString> StringArray;
	TArray<FCharacterStats> Stats;

	Str = LoadFileToString("CharacterStats.csv");
	StringArray = CsvParsing(Str, 7);
	Stats = LoadStatsToArray(StringArray, 7);

	FColor PrintColor;

	for (int i = 0; i < Stats.Num(); i++)
	{
		if (i % 2 == 0)
		{
			PrintColor = FColor::Cyan;
		}
		else
		{
			PrintColor = FColor::Orange;
		}


		//PrintColor = FColor::Green;
		GEngine->AddOnScreenDebugMessage(-1, 9999, PrintColor, (Stats[i].Name));
		GEngine->AddOnScreenDebugMessage(-1, 9999, PrintColor, FString::FromInt(Stats[i].Health));
		GEngine->AddOnScreenDebugMessage(-1, 9999, PrintColor, FString::FromInt(Stats[i].Attack));
		GEngine->AddOnScreenDebugMessage(-1, 9999, PrintColor, FString::FromInt(Stats[i].Defence));
		GEngine->AddOnScreenDebugMessage(-1, 9999, PrintColor, FString::FromInt(Stats[i].Magic_Power));
		GEngine->AddOnScreenDebugMessage(-1, 9999, PrintColor, FString::FromInt(Stats[i].Magic_Healing));
		GEngine->AddOnScreenDebugMessage(-1, 9999, PrintColor, FString::FromInt(Stats[i].Luck));
	}

}

// Called every frame
void AStatsManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<FString> AStatsManager::LoadFileToStringArray(FString Filename)
{
	FString directory = FPaths::ProjectDir();
	TArray<FString> result;
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();

	if (file.CreateDirectory(*directory))
	{
		FString myFile = directory + "/" + Filename;

		FFileHelper::LoadFileToStringArray(result, *myFile);
	}
	return result;
}

FString AStatsManager::LoadFileToString(FString Filename)
{
	FString directory = FPaths::GameSourceDir();
	FString result;

	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();

	if (file.CreateDirectory(*directory))
	{
		FString myFile = directory + "/" + Filename;
		FFileHelper::LoadFileToString(result, *myFile);
	}

	return result;
}

TArray<FString> AStatsManager::CsvParsing(const FString _String, const int32 totalColumns)
{
	TArray<FString> CsvArray;
	int32 currentColumn = 0;
	int32 currentArrayIndex = 0;

	for (int i = 0; i < _String.Len(); i++)
	{
		if (currentColumn < totalColumns)
		{
			if (_String[i] == ',' || _String[i] == '\n' || _String[i] == '\r')
			{
				currentColumn++;
				i++;
				continue;
			}
			continue;
		}
		else
		{
			if (CsvArray.Num() == 0)
			{
				CsvArray.Add(FString::Chr(_String[i]));
			}
			else
			{
				switch (_String[i])
				{
				case ',':
					// Adding a null character.
					CsvArray.Add(FString::Chr('\0'));
					currentArrayIndex++;
					break;

				case '\n':

					break;

				case '\r':
					// Adding a null character.
					currentArrayIndex++;
					CsvArray.Add(FString::Chr('\0'));

					break;

				default:
					CsvArray[currentArrayIndex].AppendChar(_String[i]);
					break;
				}
			}
		}
	}

	return CsvArray;
}

TArray<FCharacterStats> AStatsManager::LoadStatsToArray(const TArray<FString> ParsedStringArray, const int32 numberOfDataPoints)
{

	int totalStructAmount;
	int currentDataPoint = 0;
	// This calculation can break. The length of the array could add one to the ParesedStringArray.NUM() .

	totalStructAmount = (ParsedStringArray.Num()) / numberOfDataPoints;

	TArray<FCharacterStats> StatArray;
	for (int i = 0; i < totalStructAmount; i++)
	{

		FCharacterStats newStat = FCharacterStats(
			ParsedStringArray[currentDataPoint],
			FCString::Atoi(*ParsedStringArray[currentDataPoint + 1]),
			FCString::Atoi(*ParsedStringArray[currentDataPoint + 2]),
			FCString::Atoi(*ParsedStringArray[currentDataPoint + 3]),
			FCString::Atoi(*ParsedStringArray[currentDataPoint + 4]),
			FCString::Atoi(*ParsedStringArray[currentDataPoint + 5]),
			FCString::Atoi(*ParsedStringArray[currentDataPoint + 6])
		);
		StatArray.Add(newStat);
		currentDataPoint += numberOfDataPoints;
	}
	return StatArray;
}