// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/HealthComponent.h"
#include "Interface/HealthInterface.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::LoseHealth(float Amount)
{
	Health -= Amount;
	if (GetOwner()->Implements<UHealthInterface>())
	{
		IHealthInterface::Execute_Damage(GetOwner());
	}
	if (Health <= 0.f)
	{
		Health = 0.f;
		if (GetOwner()->Implements<UHealthInterface>())
		{
			IHealthInterface::Execute_Death(GetOwner());
		}
	}
}

