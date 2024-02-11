#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"


UENUM(BlueprintType)
enum class FactoryModuleStateEnum : uint8
{
	Iddle = 0 UMETA(DisplayName = "Iddle"),
	Work = 1 UMETA(DisplayName = "Work"),
	Error = 2 UMETA(DisplayName = "Error"),
};
