// Fill out your copyright notice in the Description page of Project Settings.


#include "XSaveGameSubsystem.h"

void UXSaveGameSubsystem::clearSaveData()
{
	this->saveData.Empty();
}

void UXSaveGameSubsystem::WriteSaveGame()
{
	this->CurrentSaveGame->saveData.Empty();
	for (int k = 0; k < this->saveData.Num(); k++)
	{
		this->CurrentSaveGame->saveData.Add(this->saveData[k]);
	}

	UGameplayStatics::SaveGameToSlot(this->CurrentSaveGame, this->CurrentSlotName, 0);
	this->saveData.Empty();
	OnSaveGameWritten.Broadcast(this->CurrentSaveGame);
}

void UXSaveGameSubsystem::LoadSaveGame(FString InSlotName)
{
	this->CurrentSaveGame->BeginDestroy();
	// Retrieve and cast the USaveGame object to UMySaveGame.
	this->CurrentSaveGame = Cast<UXSaveGame>(UGameplayStatics::LoadGameFromSlot(this->CurrentSlotName, 0));
	if (this->CurrentSaveGame)
	{
		// The operation was successful, so LoadedGame now contains the data we saved earlier.
		UE_LOG(LogTemp, Warning, TEXT("SAVE_GAME_SUBSYSTEM: LOADED: DONE"));
	}
}

void UXSaveGameSubsystem::addSaveData(FString _saveData)
{
	this->saveData.Add(_saveData);
}

void UXSaveGameSubsystem::addAllSpaceObjects()
{
}

void UXSaveGameSubsystem::Initialize(FSubsystemCollectionBase & Collection)
{
	// load config
	this->configSave = Cast<UXSaveConfig>(UGameplayStatics::LoadGameFromSlot(TEXT(SAVE_CONFIG_SLOT_NAME), 0));
	if (!this->configSave)
	{
		this->configSave = Cast<UXSaveConfig>(UGameplayStatics::CreateSaveGameObject(UXSaveConfig::StaticClass()));
		this->configSave->SaveSlotName = TEXT(SAVE_CONFIG_SLOT_NAME);
		this->configSave->saveSlotList.Add(TEXT("saveSlot_0"));
		UGameplayStatics::SaveGameToSlot(this->configSave, TEXT(SAVE_CONFIG_SLOT_NAME), 0);
		UE_LOG(LogTemp, Warning, TEXT("SAVE_GAME_SUBSYSTEM: save config"));
	}

	this->CurrentSaveGame = Cast<UXSaveGame>(UGameplayStatics::CreateSaveGameObject(UXSaveGame::StaticClass()));
}
