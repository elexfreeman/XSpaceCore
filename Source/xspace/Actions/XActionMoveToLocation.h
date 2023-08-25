// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Base/XAction.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/KismetMathLibrary.h"
#include "../Base/FlyData.h"


#include "XActionMoveToLocation.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(AA_ActionMoveToLocLog, Log, All);

/**
 *
 */
UCLASS(Blueprintable)
class XSPACE_API UXActionMoveToLocation : public UXAction
{
	GENERATED_BODY()
public:

	UFlyData* flyData = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Target location")
	)
		FVector targetLocation = FVector(0, 0, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Start location")
	)
		FVector startLocation = FVector(0, 0, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Total distance")
	)
		float totalDistance = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "")
	)
		float currentDistance = 0;

	UFUNCTION(BlueprintCallable, Category = "AA_Lib")
		void Init(
			UFlyData* _flyData,
			FVector _targetLocation
		);

	bool Do(float deltaTime) override;
};
