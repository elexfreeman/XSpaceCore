// Fill out your copyright notice in the Description page of Project Settings.

#include "XCore.h"


// Sets default values
AXCore::AXCore()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AXCore::BeginPlay()
{
	Super::BeginPlay();
	//this->spaceWorld = NewObject<USpaceWorld>();
}
void AXCore::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
}

// Called every frame
void AXCore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AXCore::saveGameTest()
{
}

