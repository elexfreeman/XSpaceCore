// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyData.h"

FVector UFlyData::GetActorForwardVector()
{
	return	UKismetMathLibrary::GetForwardVector(this->rotation);
}

void UFlyData::setSaveData(FString _saveData)
{
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(_saveData);
	TSharedPtr<FJsonObject> jsonData = MakeShareable(new FJsonObject);
	FJsonSerializer::Deserialize(JsonReader, jsonData);

	FString name;
	jsonData->TryGetStringField("name", name);

	if (name.Compare(TEXT("FlyData"))) {
		return;
	}

	this->currentSpeed = jsonData->GetNumberField("currentSpeed");
	this->brakingDistances = jsonData->GetNumberField("brakingDistances");
	this->stopDistances = jsonData->GetNumberField("stopDistances");
	this->brakingPower = jsonData->GetNumberField("brakingPower");
	this->stopDistances = jsonData->GetNumberField("stopDistances");
	this->brakingPower = jsonData->GetNumberField("brakingPower");
	this->accelerationPower = jsonData->GetNumberField("accelerationPower");
	this->rotationPower = jsonData->GetNumberField("rotationPower");
	this->maxSpeed = jsonData->GetNumberField("maxSpeed");
	this->massa = jsonData->GetNumberField("massa");
	this->volume = jsonData->GetNumberField("volume");
	this->radius = jsonData->GetNumberField("radius");

	this->rotation.InitFromString(jsonData->GetStringField("rotation"));
	this->location.InitFromString(jsonData->GetStringField("location"));
	this->forwardVector.InitFromString(jsonData->GetStringField("forwardVector"));
}

FString UFlyData::getSaveData()
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField("name", "FlyData");
	JsonObject->SetNumberField("currentSpeed", this->currentSpeed);
	JsonObject->SetNumberField("brakingDistances", this->brakingDistances);
	JsonObject->SetNumberField("stopDistances", this->stopDistances);
	JsonObject->SetNumberField("brakingPower", this->brakingPower);
	JsonObject->SetNumberField("stopDistances", this->stopDistances);
	JsonObject->SetNumberField("brakingPower", this->brakingPower);
	JsonObject->SetNumberField("accelerationPower", this->accelerationPower);
	JsonObject->SetNumberField("rotationPower", this->rotationPower);
	JsonObject->SetNumberField("maxSpeed", this->maxSpeed);
	JsonObject->SetNumberField("massa", this->massa);
	JsonObject->SetNumberField("volume", this->volume);
	JsonObject->SetNumberField("radius", this->radius);
	JsonObject->SetStringField("rotation", this->rotation.ToString());
	JsonObject->SetStringField("location", this->location.ToString());
	JsonObject->SetStringField("forwardVector", this->forwardVector.ToString());


	FString OutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);


	return OutputString;
}
