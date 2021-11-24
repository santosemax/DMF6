// (c) Malachias Harris.

#pragma once

#include "CoreMinimal.h"
#include "StatsStruct.generated.h"

USTRUCT(BlueprintType)
struct CSVREADER_API FCharacterStats
{
	GENERATED_BODY()

		FORCEINLINE FCharacterStats();
	explicit FORCEINLINE FCharacterStats(FString _Name, int32 _Health, int32 _Attack, int32 _Defence, int32 _Magic_Power, int32 _Magic_Healing, int32 _Luck);

	FString Name;
	int32 Health;
	int32 Attack;
	int32 Defence;
	int32 Magic_Power;
	int32 Magic_Healing;
	int32 Luck;
};

FORCEINLINE FCharacterStats::FCharacterStats()
{

}

FORCEINLINE FCharacterStats::FCharacterStats(FString _Name, int32 _Health, int32 _Attack, int32 _Defence, int32 _Magic_Power, int32 _Magic_Healing, int32 _Luck)
	:Name(_Name), Health(_Health), Attack(_Attack), Defence(_Defence), Magic_Power(_Magic_Power), Magic_Healing(_Magic_Healing), Luck(_Luck)
{

}