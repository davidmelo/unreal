// Fill out your copyright notice in the Description page of Project Settings.

#include "Sample.h"
#include "SampleHealthInterface.h"

USampleHealthInterface::USampleHealthInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

float ISampleHealthInterface::GetHealth() const
{
	return Health;
}

void ISampleHealthInterface::SetHealth(float NewHealth)
{
	Health = NewHealth;
}

float ISampleHealthInterface::GetMaxHealth() const
{
	return MaxHealth;
}

void ISampleHealthInterface::SetMaxHealth(float NewMaxHealth)
{
	ISampleHealthInterface::MaxHealth = NewMaxHealth;
}

void ISampleHealthInterface::ResetHealth()
{
	Health = MaxHealth;
}

bool ISampleHealthInterface::IsDead() const
{
	return GetHealth() <= 0;
}

bool ISampleHealthInterface::IsAlive() const
{
	return GetHealth() > 0;
}
