// Fill out your copyright notice in the Description page of Project Settings.


#include "XSaveGameSubsystem.h"

void UXSaveGameSubsystem::WriteSaveGame()
{
	this->CurrentSaveGame->saveData.Empty();
	for (int k = 0; k < this->saveData.Num(); k++)
	{
		this->CurrentSaveGame->saveData.Add(this->saveData[k]);
	}

	UGameplayStatics::SaveGameToSlot(CurrentSaveGame, CurrentSlotName, 0);
	OnSaveGameWritten.Broadcast(CurrentSaveGame);
}

void UXSaveGameSubsystem::LoadSaveGame(FString InSlotName)
{
}

void UXSaveGameSubsystem::addSaveData(FString _saveData)
{
	this->saveData.Add(_saveData);
}

void UXSaveGameSubsystem::Initialize(FSubsystemCollectionBase & Collection)
{
	this->CurrentSaveGame = Cast<UXSaveGame>(UGameplayStatics::CreateSaveGameObject(UXSaveGame::StaticClass()));
}
