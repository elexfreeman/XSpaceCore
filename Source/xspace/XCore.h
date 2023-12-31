// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

#include "XCore.generated.h"

UCLASS()
class XSPACE_API AXCore : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AXCore();

protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void saveGameTest();

};
