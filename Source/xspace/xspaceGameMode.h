// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/Actor.h"

#include "./Base/XNameGenerator.h"		
#include "./Base/SpaceWorld.h"		

#include "xspaceGameMode.generated.h"

UCLASS(MinimalAPI)
class AxspaceGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AxspaceGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		UXNameGenerator* xNameGenerator = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		USpaceWorld* xSpaceWorld = nullptr;



};



