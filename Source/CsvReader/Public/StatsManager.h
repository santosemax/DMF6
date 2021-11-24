// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StatsManager.generated.h"

struct FCharacterStats;

UCLASS()
class CSVREADER_API AStatsManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AStatsManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	TArray <FCharacterStats*> Characters;

private:
	TArray<FString> LoadFileToStringArray(FString Filename);
	FString LoadFileToString(FString Filename);
	TArray<FString> CsvParsing(const FString _String, const int32 totalColumns);

	TArray<FCharacterStats> LoadStatsToArray(const TArray<FString> ParsedStringArray, const int32 numberOfDataPoints);

};