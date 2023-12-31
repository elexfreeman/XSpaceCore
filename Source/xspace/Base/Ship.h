// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "./SpaceObject.h"
#include "./ShipModule.h"
#include "../Actions/XActionMoveToLocation.h"
#include "../Actions/XActionFollowActor.h"
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
		Category = "AA", meta = (ToolTip = "Module list")
	)
		TArray<AShipModule*> shipModuleList;

	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Inner Core tick"))
		void moveToLocation(
			FVector _targetLocation
		);

	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Follow to actor"))
		void followActor(
			AActor* _target
		);


	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Init space object"))
		void Init();
};
