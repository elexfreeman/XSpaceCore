// Fill out your copyright notice in the Description page of Project Settings.


#include "XAction.h"

void UXAction::Init(FString _name, FString _worldCode, AActor* _owner)
{
	this->name = _name;
	this->worldCode = _worldCode;
	this->owner = _owner;
}
bool UXAction::Do(float deltaTime)
{
	return false;
}

FString UXAction::getSaveData()
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField("name", this->name);
	JsonObject->SetStringField("className", this->GetClass()->GetName());
	JsonObject->SetStringField("worldCode", this->worldCode);
	JsonObject->SetNumberField("state", (double)this->state);
	JsonObject->SetBoolField("isNeedBreak", this->isNeedBreak);

	FString OutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	return OutputString;
}

void UXAction::setSaveData(FString saveData)
{
}
