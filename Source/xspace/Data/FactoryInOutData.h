#pragma once

#include "CoreMinimal.h"
#include "./ResourceData.h"

#include "FactoryInOutData.generated.h"

USTRUCT(BlueprintType)
struct FFactoryInOutData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AA)
		FResourceData resource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AA)
		int resourceSize = 10;
};
