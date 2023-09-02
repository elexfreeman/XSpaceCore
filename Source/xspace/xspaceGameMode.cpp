// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "xspaceGameMode.h"
#include "xspacePawn.h"

AxspaceGameMode::AxspaceGameMode()
{
	// set default pawn class to our flying pawn
	DefaultPawnClass = AxspacePawn::StaticClass();

	this->xNameGenerator = NewObject<UXNameGenerator>();
	this->xSpaceWorld = NewObject<USpaceWorld>();
//	PrimaryActorTick.bStartWithTickEnabled = true;
//	PrimaryActorTick.bCanEverTick = true;

}
// Called every frame
void AxspaceGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AxspaceGameMode::addXAction(UXAction * _xAction)
{
	this->actionQueueForWork.Enqueue(_xAction);
}

void AxspaceGameMode::addObjWithActiveAction(FString _worldKey)
{
	this->objWithActiveActions.Enqueue(_worldKey);
}

void AxspaceGameMode::addSpaceObject(FString _worldCode, AActor * spaceObject)
{
	this->xSpaceWorld->addSpaceObject(_worldCode, spaceObject);
	this->onAddSpaceObject.Broadcast(spaceObject);

}

// Called when the game starts or when spawned
void AxspaceGameMode::BeginPlay()
{
	Super::BeginPlay();
}
void AxspaceGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
}



