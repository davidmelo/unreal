// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Info.h"
#include "SampleTeamManager.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class SAMPLE_API ASampleTeamManager : public AInfo
{
	GENERATED_BODY()
	
public:

	UFUNCTION(Category = "Team", BlueprintCallable, meta = (Tooltip = "Creates a new team, returns the team ID"))
	int32 CreateTeam();

	UFUNCTION(Category = "Team", BlueprintCallable, meta = (Tooltip = "Removea a team"))
	void RemoveTeam(int32 TeamID);

	UFUNCTION(Category = "Team", BlueprintCallable, meta = (Tooltip = "Retrieve a team"))
	class ASampleTeam* GetTeam(int32 TeamID) const;

	UFUNCTION(Category = "Team", BlueprintCallable, meta = (Tooltip = "Add player to team"))
	void AddPlayer(AActor* Player, int32 TeamID);

	UFUNCTION(Category = "Team", BlueprintCallable, meta = (Tooltip = "Remove player from team"))
	void RemovePlayer(AActor* Player, int32 TeamID);

	UFUNCTION(Category = "Team", BlueprintCallable, meta = (Tooltip = "Get random player"))
	AActor* GetRandomPlayer() const;

	UFUNCTION(Category = "Team", BlueprintCallable, meta = (Tooltip = "Get random player from a team"))
	AActor* GetRandomPlayerFromTeam(int32 TeamID) const;

	UFUNCTION(Category = "Team", BlueprintCallable, meta = (Tooltip = "Get random alive player from a team"))
	AActor* GetRandomAlivePlayerFromTeam(int32 TeamID) const;

	UPROPERTY(Category = "Team", EditAnywhere, BlueprintReadWrite, meta = (Tooltip = "Team class"))
	TSubclassOf<class ASampleTeam> TeamClass;

private:

	UPROPERTY(Category = "Team", VisibleAnywhere, meta = (Tooltip = "Teams"))
	TArray<class ASampleTeam*> Teams;
	
};
