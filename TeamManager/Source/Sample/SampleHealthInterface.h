// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SampleHealthInterface.generated.h"

UINTERFACE(meta = (CannotImplementInterfaceInBlueprint))
class USampleHealthInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class ISampleHealthInterface
{
	GENERATED_IINTERFACE_BODY()

public:

	UFUNCTION(Category = "Health", BlueprintCallable, meta = (Tooltip = "Get health"))
	virtual float GetHealth() const;

	UFUNCTION(Category = "Health", BlueprintCallable, meta = (Tooltip = "Set health"))
	virtual void SetHealth(float NewHealth);

	UFUNCTION(Category = "Health", BlueprintCallable, meta = (Tooltip = "Get maximum health"))
	virtual float GetMaxHealth() const;

	UFUNCTION(Category = "Health", BlueprintCallable, meta = (Tooltip = "Set maximum health"))
	virtual void SetMaxHealth(float NewMaxHealth);

	UFUNCTION(Category = "Health", BlueprintCallable, meta = (Tooltip = "Reset health, setting it back to maximum health"))
	virtual void ResetHealth();

	UFUNCTION(Category = "Health", BlueprintCallable, meta = (Tooltip = "Is it dead?"))
	virtual bool IsDead() const;

	UFUNCTION(Category = "Health", BlueprintCallable, meta = (Tooltip = "Is it alive?"))
	virtual bool IsAlive() const;

private:

	float Health = 100.0f;

	float MaxHealth = 100.0f;
};