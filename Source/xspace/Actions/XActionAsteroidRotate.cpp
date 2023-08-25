// Fill out your copyright notice in the Description page of Project Settings.


#include "XActionAsteroidRotate.h"
void UXActionAsteroidRotate::Init(
	UFlyData* _flyData,
	float _rotationSpeed
)
{
	Super::Init(TEXT("XActionAsteroidRotate"));
	// Generate random pitch, yaw, and roll values
	float RandomPitch = FMath::RandRange(-90.0f, 90.0f); // Random pitch between -90 and 90 degrees
	float RandomYaw = FMath::RandRange(0.0f, 360.0f);    // Random yaw between 0 and 360 degrees
	float RandomRoll = FMath::RandRange(-180.0f, 180.0f); // Random roll between -180 and 180 degrees

	// Create the random FRotator using the generated values
	this->rotator = FRotator(RandomPitch, RandomYaw, RandomRoll);
	this->flyData = _flyData;
	this->rotationSpeed = _rotationSpeed;
}

bool UXActionAsteroidRotate::Do(float deltaTime)
{
	this->flyData->rotation += this->rotator *(deltaTime * this->rotationSpeed / this->flyData->massa);
	return true;
}
