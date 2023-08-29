// Fill out your copyright notice in the Description page of Project Settings.


#include "Ship.h"

void AShip::moveToLocation(
	FVector _targetLocation
)
{
	UXActionMoveToLocation* xActionMoveToLocation = NewObject<UXActionMoveToLocation>();
	xActionMoveToLocation->Init(
		this,
		this->worldCode,
		this->flyData,
		_targetLocation
	);

	this->gameMode->addXAction(xActionMoveToLocation);
}

void AShip::followActor(AActor * _target)
{
	UXActionFollowActor* xActionFollowActor = NewObject<UXActionFollowActor>();
	xActionFollowActor->Init(
		this,
		this->worldCode,
		this->flyData,
		_target
	);

	this->gameMode->addXAction(xActionFollowActor);
}

void AShip::Init()
{
	Super::Init(TEXT("Ship"));
}
