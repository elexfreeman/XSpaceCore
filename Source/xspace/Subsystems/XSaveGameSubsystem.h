// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "./XSaveGame.h"
#include "XSaveGameSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSaveGameSignature, class UXSaveGame*, SaveObject);
/**
 *
 */
UCLASS()
class XSPACE_API UXSaveGameSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
protected:

	FString CurrentSlotName = TEXT("XDefaultSaveSlot");

	UXSaveGame* CurrentSaveGame = nullptr;

public:

	UPROPERTY(VisibleAnywhere, Category = "AA_SaveGame")
		TArray<FString> saveData;

	UFUNCTION(BlueprintCallable, Category = "AA_SaveGame")
		void WriteSaveGame();

	UFUNCTION(BlueprintCallable, Category = "AA_SaveGame")
	void LoadSaveGame(FString InSlotName = "");

	UFUNCTION(BlueprintCallable, Category = "AA_SaveGame")
	void addSaveData(FString _saveData = "");


	UPROPERTY(BlueprintAssignable)
		FOnSaveGameSignature OnSaveGameLoaded;

	UPROPERTY(BlueprintAssignable)
		FOnSaveGameSignature OnSaveGameWritten;

	/* Initialize Subsystem, good moment to load in SaveGameSettings variables */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
};
