// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "./xBaseLuner.h"
#include "../Data/ResourceData.h"
#include "xResource.generated.h"

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FA_on_get_resource);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FA_on_resource_empty);

/**
 *
 */
UCLASS()
class XSPACE_API AxResource : public AxBaseLuner
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "AA_Events")
		FA_on_get_resource on_get_resource;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "AA_Events")
		FA_on_resource_empty on_resource_empty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		bool is_empty = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		FResourceData resourceData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int count = 1000;

	UFUNCTION(BlueprintCallable, Category = "AA")
		int getResource(int _count);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AA")
		FVector getDockingLocation()  const;
};
