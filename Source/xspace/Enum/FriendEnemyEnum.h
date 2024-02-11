#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"


UENUM(BlueprintType)
enum class FriendEnemyEnum : uint8
{
	Player = 0 UMETA(DisplayName = "Player"),
	Ally = 1 UMETA(DisplayName = "Ally"),
	Neutral = 2 UMETA(DisplayName = "Neutral"),
	Enemy = 3 UMETA(DisplayName = "Enemy"),
};
