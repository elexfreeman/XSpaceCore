// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "XSaveConfig.generated.h"

/**
 *
 */
UCLASS()
class XSPACE_API UXSaveConfig : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = "AA_SaveGame")
		TArray<FString> saveSlotList;

	UPROPERTY(VisibleAnywhere, Category = "AA_SaveGame")
		FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = "AA_SaveGame")
		uint32 UserIndex;

	UXSaveConfig();
};
