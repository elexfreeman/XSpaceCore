// Fill out your copyright notice in the Description page of Project Settings.


#include "XBaseSpaceObject.h"

// Sets default values
AXBaseSpaceObject::AXBaseSpaceObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AXBaseSpaceObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AXBaseSpaceObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FString AXBaseSpaceObject::getSaveData()
{
	return FString();
}
