// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Base/XAction.h"
#include "XActionDelay.generated.h"

/**
 * 
 */
UCLASS()
class XSPACE_API UXActionDelay : public UXAction
{
	GENERATED_BODY()

protected:
	float delayTime = 0;
public:

	UFUNCTION(BlueprintCallable, Category = "AA_Lib")
		void Init(
			AActor* _owner,
			FString _worldCode,
			float _delayTime
		);

	bool Do(float deltaTime) override;
};
