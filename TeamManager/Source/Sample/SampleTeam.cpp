// Fill out your copyright notice in the Description page of Project Settings.

#include "Sample.h"
#include "SampleTeam.h"

#include "SampleHealthInterface.h"

void ASampleTeam::AddPlayer(AActor* Player)
{
	Players.Add(Player);
}

void ASampleTeam::RemovePlayer(AActor* Player)
{
	Players.Remove(Player);
}

bool ASampleTeam::ContainsPlayer(AActor* Player) const
{
	return Players.Contains(Player);
}

int32 ASampleTeam::GetSize() const
{
	return Players.Num();
}

AActor* ASampleTeam::GetRandomPlayer() const
{
	if (Players.Num() > 0)
	{
		return Players[FMath::RandRange(0, Players.Num() - 1)];
	}

	return nullptr;
}

AActor* ASampleTeam::GetRandomAlivePlayer() const
{
	// gather alive players
	TArray<AActor*> AlivePlayers;
	for (AActor* Player : Players)
	{
		ISampleHealthInterface* HealthPlayer = Cast<ISampleHealthInterface>(Player);
		if (HealthPlayer && HealthPlayer->IsAlive())
		{
			AlivePlayers.Add(Player);
		}
	}

	// return random one
	if (AlivePlayers.Num() > 0)
	{
		return AlivePlayers[FMath::RandRange(0, AlivePlayers.Num() - 1)];
	}

	return nullptr;
}

void ASampleTeam::SetID(int32 NewID) 
{ 
	ID = NewID; 
}

int32 ASampleTeam::GetID() const
{ 
	return ID; 
}
