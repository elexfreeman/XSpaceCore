// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "./SpaceObject.h"
#include "./ShipModule.h"
#include "../Actions/XActionMoveToLocation.h"
#include "Ship.generated.h"

/**
 *
 */
UCLASS()
class XSPACE_API AShip : public ASpaceObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA_Fly", meta = (ToolTip = "Braking distances (m)")
	)
		float brakingDistances = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA_Fly", meta = (ToolTip = "Max speed time (sec)")
	)
		float maxSpeedTime = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA_Fly", meta = (ToolTip = "Max speed (m/s)")
	)
		float maxSpeed = 100;


	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Module list")
	)
		TArray<AShipModule*> shipModuleList;

	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Inner Core tick"))
		void moveToLocation(
			FVector _targetLocation,
			float _speed,
			float _brakingDistances,
			float _maxSpeedTime,
			float _accelerationPower
		);

};
