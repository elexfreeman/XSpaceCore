// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#define SAVE_CONFIG_SLOT_NAME "xSaveConfigSlot"

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "./XSaveGame.h"
#include "./XSaveConfig.h"
#include "XSaveGameSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSaveGameSignature, class UXSaveGame*, SaveObject);

UCLASS()
class XSPACE_API UXSaveGameSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
protected:

	FString CurrentSlotName = TEXT("XDefaultSaveSlot");
	// TODO: save slot list
	UXSaveGame* CurrentSaveGame = nullptr;

	UXSaveConfig* configSave = nullptr;

public:

	UPROPERTY(BlueprintAssignable)
		FOnSaveGameSignature OnSaveGameLoaded;

	UPROPERTY(BlueprintAssignable)
		FOnSaveGameSignature OnSaveGameWritten;

	//-------------------

	UPROPERTY(VisibleAnywhere, Category = "AA_SaveGame")
		TArray<UXSaveGame*> saveGameList;

	UPROPERTY(VisibleAnywhere, Category = "AA_SaveGame")
		TArray<FString> saveData;

	//-----------------------
	UFUNCTION(BlueprintCallable, Category = "AA_SaveGame")
		void clearSaveData();

	UFUNCTION(BlueprintCallable, Category = "AA_SaveGame")
		void WriteSaveGame();

	UFUNCTION(BlueprintCallable, Category = "AA_SaveGame")
		void LoadSaveGame(FString InSlotName = "");

	UFUNCTION(BlueprintCallable, Category = "AA_SaveGame")
		void addSaveData(FString _saveData = "");

	UFUNCTION(BlueprintCallable, Category = "AA_SaveGame")
		void addAllSpaceObjects();

	/* Initialize Subsystem, good moment to load in SaveGameSettings variables */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
};
