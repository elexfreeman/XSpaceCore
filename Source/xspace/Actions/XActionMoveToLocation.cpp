// Fill out your copyright notice in the Description page of Project Settings.


#include "XActionMoveToLocation.h"

DEFINE_LOG_CATEGORY(AA_ActionMoveToLocLog);

void UXActionMoveToLocation::Init(
	UFlyData* _flyData,
	FVector _targetLocation
)
{
	Super::Init(TEXT("XActionMoveToLocation"));

	this->flyData = _flyData;
	this->targetLocation = _targetLocation;

	this->startLocation = this->flyData->rootActor->GetActorLocation();
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


	this->currentDistance = FVector::Distance(this->flyData->rootActor->GetActorLocation(), this->targetLocation);

	if (this->currentDistance > this->flyData->stopDistances)
	{
		FVector location = this->flyData->rootActor->GetActorLocation();
		FVector forward = this->flyData->rootActor->GetActorForwardVector();

		//==============================================
		//==================== ROTATION ================
		//==============================================
		FRotator CurrentRotation = this->flyData->rootActor->GetActorRotation();

		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(location, this->targetLocation);
		FRotator NewRotation = FMath::RInterpTo(
			CurrentRotation,
			LookAtRotation,
			deltaTime,
			this->flyData->rotationPower
		);
		//FRotator NewRotation = LookAtRotation;
		this->flyData->rootActor->SetActorRotation(NewRotation);
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
		this->flyData->rootActor->SetActorLocation(location);


		//FVector newLocation = FMath::VInterpTo(location, this->targetLocation, deltaTime, this->flyData->maxSpeed);
		//this->flyData->rootActor->SetActorLocation(newLocation);


		return true;
	}
	return false;

	return true;
}
