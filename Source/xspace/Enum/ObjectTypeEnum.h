#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"


UENUM(BlueprintType)
enum class ObjectTypeEnum : uint8
{
	Ship = 0 UMETA(DisplayName = "Ship"),
	Resource = 1 UMETA(DisplayName = "Resource"),
	Factory = 2 UMETA(DisplayName = "Factory"),
	Static = 3 UMETA(DisplayName = "Static"),
};
