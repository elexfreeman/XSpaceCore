// Fill out your copyright notice in the Description page of Project Settings.


#include "xBaseCargoItem.h"

FString UxBaseCargoItem::getSaveData()
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField("name", this->name);
	JsonObject->SetStringField("description", this->description);
	JsonObject->SetNumberField("volume", this->volume);
	JsonObject->SetNumberField("count", this->count);


	FString OutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	return OutputString;
}

void UxBaseCargoItem::setSaveData(FString _saveData)
{
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(_saveData);
	TSharedPtr<FJsonObject> jsonData = MakeShareable(new FJsonObject);
	FJsonSerializer::Deserialize(JsonReader, jsonData);

	jsonData->TryGetStringField("name", this->name);
	jsonData->TryGetStringField("description", this->description);
	this->volume = jsonData->GetNumberField("volume");
	this->count = jsonData->GetNumberField("count");
}

