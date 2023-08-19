// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Base/XAction.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"

#include "XActionMoveToLocation.generated.h"

/**
 *
 */
UCLASS()
class XSPACE_API UXActionMoveToLocation : public UXAction
{
	GENERATED_BODY()
public:

	AActor* actor = nullptr;
	FVector targetLocation;
	FVector startLocation;
	FVector direction;
	float speed = 0;
	float totalDistance = 0;
	float currentDistance = 0;

	float InterpolationTime = 0.0f;
	float InterpolationDuration = 2.0f; // Duration of the interpolation in seconds

	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Inner Core tick"))
		void Init(
			AActor* _actor,
			FVector _targetLocation,
			float _speed
		);

	bool Do(float deltaTime) override;
};
