// Fill out your copyright notice in the Description page of Project Settings.


#include "XActionFollowActor.h"

DEFINE_LOG_CATEGORY(AA_ActionFollowActorLog);

void UXActionFollowActor::Init(
	UFlyData* _flyData,
	AActor* _target
)
{
	Super::Init(TEXT("XActionFollowActor"));

	this->flyData = _flyData;
	this->target = _target;
}

bool UXActionFollowActor::Do(float deltaTime)
{

	Super::Do(deltaTime);

	//	CountdownTimeMS -= static_cast<int32>(deltaTime * 1000); // Convert DeltaTime to milliseconds
			// Display remaining time on the screen
		//	GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, FString::Printf(TEXT("Countdown: %d ms"), CountdownTimeMS));

	FVector targetLocation = this->target->GetActorLocation();

	this->startLocation = this->flyData->rootActor->GetActorLocation();
	this->currentDistance = FVector::Distance(this->startLocation, targetLocation);

	if (this->currentDistance > this->flyData->stopDistances)
	{
		FVector location = this->flyData->rootActor->GetActorLocation();
		FVector forward = this->flyData->rootActor->GetActorForwardVector();

		//==============================================
		//==================== ROTATION ================
		//==============================================
		FRotator CurrentRotation = this->flyData->rootActor->GetActorRotation();

		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(location, targetLocation);
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
