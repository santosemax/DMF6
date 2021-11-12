// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#define D(x) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT(x));}

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	maxHealth = 100;
	health = maxHealth;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* owner = GetOwner();
	if(owner)
	{
		//Binds our take damage function to the OnTakeAnyDamage function so it gets called right after!
		owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::takeDamage);
	}
	
}

void UHealthComponent::takeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	if(Damage <= 0 )
		return;

	D("The damaged Actor is: "+ DamagedActor->GetName());

	health = FMath::Clamp(health - Damage, 0.0f, maxHealth);
	
}

