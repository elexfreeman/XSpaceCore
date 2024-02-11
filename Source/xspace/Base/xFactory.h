// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "./xBaseLuner.h"
#include "./xFactoryModule.h"

#include "xFactory.generated.h"

/**
 *
 */
UCLASS()
class XSPACE_API AxFactory : public AxBaseLuner
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "List of factory modules")
	)
		TArray<AxFactoryModule*> moduleList;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AA")
		FVector getDockingLocation()  const;
};
