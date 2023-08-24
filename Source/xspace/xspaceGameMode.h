// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "./Base/XNameGenerator.h"		

#include "xspaceGameMode.generated.h"

UCLASS(MinimalAPI)
class AxspaceGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AxspaceGameMode();

	UXNameGenerator* xNameGenerator = nullptr;
};



