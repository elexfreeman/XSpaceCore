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

void AShip::Init()
{
	Super::Init(TEXT("Ship"));
}
