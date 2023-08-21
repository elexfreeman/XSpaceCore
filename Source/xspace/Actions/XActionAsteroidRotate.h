// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Base/XAction.h"
#include "GameFramework/Actor.h"
#include "XActionAsteroidRotate.generated.h"

/**
 *
 */
UCLASS()
class XSPACE_API UXActionAsteroidRotate : public UXAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Rotator")
	)
		AActor* rotationTarget = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Rotator")
	)
		FRotator rotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Rotator")
	)
		float rotationSpeed = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Asteroid massa")
	)
		float asteroidMassa = 100000.0f;

	void Init(AActor* _rotationTarget);

	bool Do(float deltaTime) override;


};