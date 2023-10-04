// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "xAxteroidBelt.generated.h"

UCLASS()
class XSPACE_API AxAxteroidBelt : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AxAxteroidBelt();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TArray<FVector> spawnLocationList;

	UPROPERTY(Category = Mesh, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float distanceBetween = 100;

	UPROPERTY(Category = Mesh, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		int maxCountInLocation = 5;

	UFUNCTION(BlueprintCallable, Category = "AA")
		TArray<FVector> getLocationList();
};
