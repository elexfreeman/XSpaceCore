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
	this->xActionAsteroidRotate->Init( this->flyData, this->flyData->rotationPower);

	this->actionQueue.Enqueue(this->xActionAsteroidRotate);
}
