// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Math/UnrealMathUtility.h"
#include "XNameGenerator.generated.h"

/**
 * 
 */
UCLASS()
class XSPACE_API UXNameGenerator : public UObject
{
	GENERATED_BODY()

private:
	TArray<FString> existNameList;

	FString getRandChar();
	FString getRandNumber();

public:
	FString generate(FString _startStr);
	
};
