// Fill out your copyright notice in the Description page of Project Settings.


#include "xFactoryModule.h"

// Sets default values
AxFactoryModule::AxFactoryModule()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AxFactoryModule::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(
		factoryTimerHandle, // handle to cancel timer at a later time
		this, // the owning object
		&AxFactoryModule::factoryTick, // function to call on elapsed
		this->operationTime, // float delay until elapsed
		true); // looping?
}

void AxFactoryModule::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// Ensure the fuze timer is cleared by using the timer handle
	GetWorld()->GetTimerManager().ClearTimer(factoryTimerHandle);
}

void AxFactoryModule::factoryTick()
{
	this->on_work.Broadcast();
}

// Called every frame
void AxFactoryModule::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

