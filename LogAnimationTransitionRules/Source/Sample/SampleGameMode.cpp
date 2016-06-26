// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Sample.h"
#include "SampleGameMode.h"
#include "SampleCharacter.h"

ASampleGameMode::ASampleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
