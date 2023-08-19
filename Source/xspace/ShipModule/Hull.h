// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Base/ShipModule.h"
#include "Hull.generated.h"

/**
 *
 */
UCLASS()
class XSPACE_API AHull : public AShipModule
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Volume m3")
	)
		float copacity = 0;


};
