// Fill out your copyright notice in the Description page of Project Settings.


#include "XActionMoveToLocation.h"

void UXActionMoveToLocation::Init(
	AActor* _actor,
	FVector _targetLocation,
	float _speed,
	float _brakingDistances,
	float _maxSpeedTime,
	float _accelerationPower
)
{
	this->actor = _actor;
	this->targetLocation = _targetLocation;
	this->speed = _speed;
	this->brakingDistances = _brakingDistances;
	this->maxSpeedTime = _maxSpeedTime;
	this->accelerationPower = _accelerationPower;


	this->startLocation = this->actor->GetActorLocation();
	this->totalDistance = FVector::Distance(this->startLocation, this->targetLocation);
	this->currentDistance = FVector::Distance(this->startLocation, this->targetLocation);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Init Move to locatin"));

}

bool UXActionMoveToLocation::Do(float deltaTime)
{

	Super::Do(deltaTime);

	//	CountdownTimeMS -= static_cast<int32>(deltaTime * 1000); // Convert DeltaTime to milliseconds
			// Display remaining time on the screen
		//	GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, FString::Printf(TEXT("Countdown: %d ms"), CountdownTimeMS));


	this->currentDistance = FVector::Distance(this->actor->GetActorLocation(), this->targetLocation);

	if (this->currentDistance > 10)
	{
		FVector location = this->actor->GetActorLocation();
		FVector forward = this->actor->GetActorForwardVector();

		// TODO: masssa and accelerationPower
		// TODO: time of speed max from massa and max speed

		this->currentSpeed = FMath::FInterpConstantTo(this->currentSpeed, this->speed, deltaTime, this->accelerationPower);

		GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, FString::Printf(TEXT("Speed: %d ms"), this->currentSpeed));
		location += forward * this->currentSpeed* deltaTime;
		this->actor->SetActorLocation(location);
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("move to"));

		//FVector newLocation = FMath::VInterpTo(location, this->targetLocation, deltaTime, this->speed);
		//this->actor->SetActorLocation(newLocation);

		//==============================================
		//==================== ROTATION ================
		//==============================================
		float RotationSpeed = 1.0f; // Adjust this value to control the rotation speed in degrees per second
		FRotator CurrentRotation = this->actor->GetActorRotation();

		FVector ForwardVector = (this->targetLocation - location).GetSafeNormal();
		FRotator LookAtRotation = ForwardVector.Rotation();

		FRotator NewRotation = FMath::RInterpTo(CurrentRotation, LookAtRotation, deltaTime, RotationSpeed);

		this->actor->SetActorRotation(NewRotation);
		return true;
	}
	return false;

	return true;
}
