// Fill out your copyright notice in the Description page of Project Settings.


#include "Ship.h"

void AShip::moveToLocation(FVector targetLocation, float speed)
{
	UXActionMoveToLocation* xActionMoveToLocation = NewObject<UXActionMoveToLocation>();
	xActionMoveToLocation->Init(
		this,
		targetLocation,
		speed
	);

	this->actionQueue.Enqueue(xActionMoveToLocation);

}