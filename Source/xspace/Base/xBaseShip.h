// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "./SpaceObject.h"
#include "xBaseShip.generated.h"

/**
 *
 */
UCLASS()
class XSPACE_API AxBaseShip : public ASpaceObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Init space object"))
		void Init(FString shipName);
};
