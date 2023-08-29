// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/KismetMathLibrary.h"

#include "../Base/XAction.h"
#include "../Base/FlyData.h"

#include "XActionFollowActor.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(AA_ActionFollowActorLog, Log, All);
/**
 *
 */
UCLASS()
class XSPACE_API UXActionFollowActor : public UXAction
{
	GENERATED_BODY()

public:

	UFlyData* flyData = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Target actor")
	)
		AActor* target = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Start location")
	)
		FVector startLocation = FVector(0, 0, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Direction")
	)
		FVector direction = FVector(0, 0, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "")
	)
		float currentDistance = 0;

	UFUNCTION(BlueprintCallable, Category = "AA_Lib")
		void Init(
			FString _worldCode,
			UFlyData* _flyData,
			AActor* _target
		);

	bool Do(float deltaTime) override;

};
