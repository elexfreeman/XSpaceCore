// Fill out your copyright notice in the Description page of Project Settings.


#include "XActionMoveToLocation.h"

DEFINE_LOG_CATEGORY(AA_ActionMoveToLocLog);

void UXActionMoveToLocation::Init(
	AActor* _owner,
	FString _worldCode,
	UFlyData* _flyData,
	FVector _targetLocation
)
{
	Super::Init(TEXT("XActionMoveToLocation"), _worldCode, _owner);

	this->flyData = _flyData;
	this->targetLocation = _targetLocation;

	this->startLocation = this->flyData->location;
	this->totalDistance = FVector::Distance(this->startLocation, this->targetLocation);
	this->currentDistance = FVector::Distance(this->startLocation, this->targetLocation);
}

bool UXActionMoveToLocation::Do(float deltaTime)
{

	Super::Do(deltaTime);

	if (this->isNeedBreak) return false;
	//	CountdownTimeMS -= static_cast<int32>(deltaTime * 1000); // Convert DeltaTime to milliseconds
			// Display remaining time on the screen
		//	GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, FString::Printf(TEXT("Countdown: %d ms"), CountdownTimeMS));


	this->currentDistance = FVector::Distance(this->flyData->location, this->targetLocation);

	if (this->currentDistance > this->flyData->stopDistances)
	{
		FVector location = this->flyData->location;
		FVector forward = this->flyData->GetActorForwardVector();

		//==============================================
		//==================== ROTATION ================
		//==============================================
		FRotator CurrentRotation = this->flyData->rotation;

		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(location, this->targetLocation);
		FRotator NewRotation = FMath::RInterpTo(
			CurrentRotation,
			LookAtRotation,
			deltaTime,
			this->flyData->rotationPower
		);
		//FRotator NewRotation = LookAtRotation;

		this->flyData->rotation = NewRotation;
		// TODO: masssa and flyData->accelerationPower
		// TODO: time of speed max from massa and max speed

		//=======================================
		//================ SPEED ================
		//=======================================

		UE_LOG(AA_ActionMoveToLocLog, Warning, TEXT("Speed: %.4f"), this->flyData->currentSpeed);

		if (this->currentDistance <= this->flyData->brakingDistances)
		{
			// breacking speed
			this->flyData->currentSpeed = FMath::FInterpConstantTo(
				this->flyData->currentSpeed,
				100, // minimus speed
				deltaTime,
				this->flyData->brakingPower
			);
		}
		else
		{
			// start speed
			this->flyData->currentSpeed = FMath::FInterpConstantTo(
				this->flyData->currentSpeed,
				this->flyData->maxSpeed,
				deltaTime,
				this->flyData->accelerationPower
			);
		}

		location += forward * this->flyData->currentSpeed* deltaTime;
		this->flyData->location = location;


		//FVector newLocation = FMath::VInterpTo(location, this->targetLocation, deltaTime, this->flyData->maxSpeed);
		//this->flyData->rootActor->SetActorLocation(newLocation);


		return true;
	}
	return false;

	return true;
}
