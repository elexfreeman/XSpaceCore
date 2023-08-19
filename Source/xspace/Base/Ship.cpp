// Fill out your copyright notice in the Description page of Project Settings.


#include "Ship.h"

void AShip::moveToLocation(
	FVector _targetLocation,
	float _speed,
	float _brakingDistances,
	float _maxSpeedTime,
	float _accelerationPower
)
{
	UXActionMoveToLocation* xActionMoveToLocation = NewObject<UXActionMoveToLocation>();
	xActionMoveToLocation->Init(
		this,
		_targetLocation,
		_speed,
		_brakingDistances,
		_maxSpeedTime,
		_accelerationPower
	);

	this->actionQueue.Enqueue(xActionMoveToLocation);

}
