#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"


UENUM(BlueprintType)
enum class XActionStateEnum : uint8
{
	Done = 0 UMETA(DisplayName = "Done", ToolTip = "Action is done"),
	Run = 1 UMETA(DisplayName = "Run", ToolTip = "Action is execute"),
};
