// Fill out your copyright notice in the Description page of Project Settings.


#include "XActionMoveToLocation.h"

void UXActionMoveToLocation::Init(
	AActor* _actor,
	FVector _targetLocation,
	float _speed
)
{
	this->actor = _actor;
	this->targetLocation = _targetLocation;
	this->speed = _speed;
	this->startLocation = this->actor->GetActorLocation();
	this->totalDistance = FVector::Distance(this->startLocation, this->targetLocation);
	this->currentDistance = FVector::Distance(this->startLocation, this->targetLocation);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Init Move to locatin"));

}

bool UXActionMoveToLocation::Do(float deltaTime)
{

	Super::Do(deltaTime);

	InterpolationTime += deltaTime;

	GEngine->AddOnScreenDebugMessage(-1, 200, FColor::Green,
		FString::Printf(TEXT("move to, curr d %d")),
		this->currentDistance
	);

	GEngine->AddOnScreenDebugMessage(-1, 200, FColor::Green,
		FString::Printf(TEXT("move to, total dist %d")),
		this->totalDistance
	);

	this->currentDistance = FVector::Distance(this->actor->GetActorLocation(), this->targetLocation);

	if (this->currentDistance > 100)
	{
		FVector location = this->actor->GetActorLocation();
		FVector forward = this->actor->GetActorForwardVector();

		location += forward * this->speed * deltaTime;
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

		//	// Calculate interpolated location
		//	float Alpha = FMath::Clamp(InterpolationTime / InterpolationDuration, 0.0f, 1.0f);
		//	FVector NewLocation = FMath::Lerp(startLocation, targetLocation, Alpha);

			// Set actor location
		//	this->actor->SetActorLocation(NewLocation);

			// Reset interpolation when complete
		//	if (InterpolationTime >= InterpolationDuration)
		//	{
		//		InterpolationTime = 0.0f;
		//		return false;
		//	}
	return true;
}
