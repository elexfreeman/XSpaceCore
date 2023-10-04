// Fill out your copyright notice in the Description page of Project Settings.


#include "XAsteroid.h"


void AXAsteroid::BeginPlay()
{
	Super::BeginPlay();
}

void AXAsteroid::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
}

void AXAsteroid::Init(float _massa, float _rotationPower, float _radius)
{
	Super::Init(TEXT("Asteroid"));

	this->flyData->massa = _massa;
	this->flyData->rotationPower = _rotationPower;
	this->flyData->radius = _radius;

	this->xActionAsteroidRotate = NewObject<UXActionAsteroidRotate>();
	this->xActionAsteroidRotate->Init(this, this->worldCode, this->flyData, this->flyData->rotationPower);

	this->currentAction = this->xActionAsteroidRotate;
	this->gameMode->addObjWithActiveAction(this->worldCode);
}

void AXAsteroid::addCompound(XOreTypeEnum compundType, float count)
{
	UxBaseOreItem* compoundItem = nullptr;
	if (compundType == XOreTypeEnum::Metallic)
	{
		compoundItem = NewObject<UMetallicOre>();
	}

	if (compundType == XOreTypeEnum::Carbonaceous)
	{
		compoundItem = NewObject<UCarbonaceousOre>();
		this->compoundList.Add(compoundItem);
	}

	if (compundType == XOreTypeEnum::Ice)
	{
		compoundItem = NewObject<UIceOre>();
		this->compoundList.Add(compoundItem);
	}

	if (compoundItem != nullptr)
	{
		compoundItem->count = count;
		this->compoundList.Add(compoundItem);
	}
}

FString AXAsteroid::getSaveData()
{
	return FString();
}
