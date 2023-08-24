// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "./SpaceObject.h"
#include "../Actions/XActionAsteroidRotate.h"
#include "XAsteroid.generated.h"

/**
 *
 */
UCLASS()
class XSPACE_API AXAsteroid : public ASpaceObject
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UXActionAsteroidRotate* xActionAsteroidRotate = nullptr;

	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Init space object"))
		void Init(float _massa, float _rotationPower, float _radius);
};
