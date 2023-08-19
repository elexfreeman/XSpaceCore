// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Base/ShipModule.h"
#include "ShieldModule.generated.h"

/**
 * 
 */
UCLASS()
class XSPACE_API AShieldModule : public AShipModule
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Copacity")
	)
		float copacity = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Regen speed")
	)
		float regenSpeed = 0;
};
