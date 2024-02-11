#pragma once

#include "CoreMinimal.h"

#include "ResourceData.generated.h"

USTRUCT(BlueprintType)
struct FResourceData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AA)
		FString name = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AA)
		FString description = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AA)
		int containerSize = 10;
};
