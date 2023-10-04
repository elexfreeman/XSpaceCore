// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "JsonUtilities/Public/JsonObjectConverter.h"
#include "xBaseCargoItem.generated.h"

/**
 *
 */
UCLASS()
class XSPACE_API UxBaseCargoItem : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA_cargo_item")
		float volume = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA_cargo_item")
		float count = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA_cargo_item")
		FString name = TEXT("Base cargo item");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA_cargo_item")
		FString description = TEXT("Base cargo item description");

	UFUNCTION(BlueprintCallable, Category = "AA_saveData")
		FString getSaveData();

	UFUNCTION(BlueprintCallable, Category = "AA_saveData")
		void setSaveData(FString _saveData);
};
