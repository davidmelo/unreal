// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Info.h"
#include "SampleTeam.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class SAMPLE_API ASampleTeam : public AInfo
{
	GENERATED_BODY()
	
public:

	UFUNCTION(Category = "Team", BlueprintCallable, meta = (Tooltip = "Add player to the team"))
	void AddPlayer(AActor* Player);

	UFUNCTION(Category = "Team", BlueprintCallable, meta = (Tooltip = "Remove player from the team"))
	void RemovePlayer(AActor* Player);

	UFUNCTION(Category = "Team", BlueprintCallable, meta = (Tooltip = "Is the player a member of this team?"))
	bool ContainsPlayer(AActor* Player) const;

	UFUNCTION(Category = "Team", BlueprintCallable, meta = (Tooltip = "Number of players in this team"))
	int32 GetSize() const;

	UFUNCTION(Category = "Team", BlueprintCallable, meta = (Tooltip = "Returns a random member of this team"))
	AActor* GetRandomPlayer() const;

	UFUNCTION(Category = "Team", BlueprintCallable, meta = (Tooltip = "Returns a random alive member of this team"))
	AActor* GetRandomAlivePlayer() const;

	UFUNCTION(Category = "Team", BlueprintCallable, meta = (Tooltip = "Set the team ID"))
	void SetID(int32 NewID);

	UFUNCTION(Category = "Team", BlueprintCallable, meta = (Tooltip = "Get the team ID"))
	int32 GetID() const;
	
private:

	UPROPERTY(Category = "Team", VisibleAnywhere, meta = (Tooltip = "Player members of the team"))
	TArray<AActor*> Players;

	UPROPERTY(Category = "Team", VisibleAnywhere, meta = (Tooltip = "Team identifier"))
	int32 ID = -1;

};
