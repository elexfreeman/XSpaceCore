// Fill out your copyright notice in the Description page of Project Settings.


#include "Ship.h"

void AShip::moveToLocation(
	FVector _targetLocation
)
{
	UXActionMoveToLocation* xActionMoveToLocation = NewObject<UXActionMoveToLocation>();
	xActionMoveToLocation->Init(
		this->flyData,
		_targetLocation
	);

	this->actionQueue.Enqueue(xActionMoveToLocation);

}

void AShip::followActor(AActor * _target)
{
	UXActionFollowActor* xActionFollowActor = NewObject<UXActionFollowActor>();
	xActionFollowActor->Init(
		this->flyData,
		_target
	);

	this->actionQueue.Enqueue(xActionFollowActor);
}

void AShip::Init()
{
	Super::Init(TEXT("Ship"));
	this->worldCode = gameMode->xNameGenerator->generate(TEXT("SP"));
}
