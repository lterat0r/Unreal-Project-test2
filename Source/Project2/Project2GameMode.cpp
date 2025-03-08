// Copyright Epic Games, Inc. All Rights Reserved.

#include "Project2GameMode.h"
#include "Project2Character.h"
#include "UObject/ConstructorHelpers.h"

AProject2GameMode::AProject2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
