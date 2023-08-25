// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Base/XAction.h"
#include "../Base/FlyData.h"
#include "XActionAsteroidRotate.generated.h"

/**
 *
 */
UCLASS()
class XSPACE_API UXActionAsteroidRotate : public UXAction
{
	GENERATED_BODY()

public:

	UFlyData* flyData = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Rotation target")
	)
		AActor* rotationTarget = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Rotator")
	)
		FRotator rotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Rotation speed")
	)
		float rotationSpeed = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Asteroid massa")
	)
		float asteroidMassa = 100000.0f;

	UFUNCTION(BlueprintCallable, Category = "AA_Lib")
	void Init(
		UFlyData* _flyData,
		float _rotationSpeed
	);

	bool Do(float deltaTime) override;

};
