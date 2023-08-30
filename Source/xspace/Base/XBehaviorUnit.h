// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "./XAction.h"

#include "XBehaviorUnit.generated.h"

/**
 *
 */
UCLASS()
class XSPACE_API UXBehaviorUnit : public UObject
{
	GENERATED_BODY()

protected:
	UXAction* xAction = nullptr;
	bool isInit = false;

public:
	UXBehaviorUnit* Init();

	// ..... other method for Behavior units extends

	UXBehaviorUnit* Next();
	UXAction* getXAction();

};
