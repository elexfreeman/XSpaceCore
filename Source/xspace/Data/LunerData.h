#pragma once

#include "CoreMinimal.h"
#include "../Enum/FriendEnemyEnum.h"
#include "../Enum/ObjectTypeEnum.h"

#include "LunerData.generated.h"

USTRUCT(BlueprintType)
struct FLunerData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AA)
		int cargoSize = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AA)
		int shieldSize = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AA)
		int hullSize = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AA)
		uint8 team = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AA)
		FriendEnemyEnum friendEnimy = FriendEnemyEnum::Neutral;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AA)
		ObjectTypeEnum objectType = ObjectTypeEnum::Ship;

};