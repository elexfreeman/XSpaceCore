// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "./SpaceObject.h"
#include "../Actions/XActionAsteroidRotate.h"
#include "../CargoItems/Ore/xBaseOreItem.h"
#include "../CargoItems/Ore/MetallicOre.h"
#include "../CargoItems/Ore/CarbonaceousOre.h"
#include "../CargoItems/Ore/IceOre.h"

#include "../CargoItems/Ore/XOreTypeEnum.h"

#include "XAsteroid.generated.h"

/**
 *
 */
UCLASS()
class XSPACE_API AXAsteroid : public ASpaceObject
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UXActionAsteroidRotate* xActionAsteroidRotate = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA" )
		TArray<UxBaseOreItem*> compoundList;

	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Init space object"))
		void Init(float _massa, float _rotationPower, float _radius);

	UFUNCTION(BlueprintCallable, Category = "AA")
		void addCompound(XOreTypeEnum compundType, float count);

	UFUNCTION(BlueprintCallable, Category = "AA")
	FString getSaveData();
};
