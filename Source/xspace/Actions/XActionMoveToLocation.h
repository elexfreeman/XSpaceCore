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
	float brakingDistances = 100;
	float maxSpeedTime = 5;
	float speed = 1000;

	FVector startLocation;
	FVector direction;
	float totalDistance = 0;
	float currentDistance = 0;

	float currentSpeed = 0;
	float accelerationPower = 100;

	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Init action move"))
		void Init(
			AActor* _actor,
			FVector _targetLocation,
			float _speed,
			float _brakingDistances,
			float _maxSpeedTime,
			float _accelerationPower
		);

	bool Do(float deltaTime) override;
};
