// Fill out your copyright notice in the Description page of Project Settings.

#include "Sample.h"
#include "SampleTeamManager.h"

#include "SampleTeam.h"

int32 ASampleTeamManager::CreateTeam()
{
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnInfo.ObjectFlags |= RF_Transient;
	ASampleTeam* Team = GetWorld()->SpawnActor<ASampleTeam>(TeamClass, SpawnInfo);

	int32 TeamID = Teams.Num();
	Team->SetID(TeamID);
	Teams.Add(Team);

	return TeamID;
}

void ASampleTeamManager::RemoveTeam(int32 TeamID)
{
	Teams.RemoveAll([TeamID](ASampleTeam* Team) { return Team->GetID() == TeamID; });
}

class ASampleTeam* ASampleTeamManager::GetTeam(int32 TeamID) const
{
	return *(Teams.FindByPredicate([TeamID](ASampleTeam* Team) { return Team->GetID() == TeamID; }));
}

void ASampleTeamManager::AddPlayer(AActor* Player, int32 TeamID)
{
	ASampleTeam* Team = GetTeam(TeamID);
	if (Team)
	{
		Team->AddPlayer(Player);
	}
}

void ASampleTeamManager::RemovePlayer(AActor* Player, int32 TeamID)
{
	ASampleTeam* Team = GetTeam(TeamID);
	if (Team)
	{
		Team->RemovePlayer(Player);
	}
}

AActor* ASampleTeamManager::GetRandomPlayer() const
{
	if (Teams.Num() != 0)
	{
		ASampleTeam* Team = Teams[FMath::RandRange(0, Teams.Num() - 1)];
		if (Team)
		{
			return Team->GetRandomPlayer();
		}
	}

	return nullptr;
}

AActor* ASampleTeamManager::GetRandomPlayerFromTeam(int32 TeamID) const
{
	ASampleTeam* Team = GetTeam(TeamID);
	if (Team)
	{
		return Team->GetRandomPlayer();
	}

	return nullptr;
}

AActor* ASampleTeamManager::GetRandomAlivePlayerFromTeam(int32 TeamID) const
{
	ASampleTeam* Team = GetTeam(TeamID);
	if (Team)
	{
		return Team->GetRandomAlivePlayer();
	}

	return nullptr;
}
