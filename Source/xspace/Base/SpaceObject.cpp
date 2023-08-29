// Fill out your copyright notice in the Description page of Project Settings.

#include "./SpaceObject.h"

void ASpaceObject::Init(
	FString _name
)
{
	this->gameMode = Cast<AxspaceGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	this->name = _name;
	this->flyData = NewObject<UFlyData>();
	this->flyData->rootActor = this;

	this->isInit = true;

	this->worldCode = this->gameMode->xNameGenerator->generate();

	this->gameMode->xSpaceWorld->addSpaceObject(this->worldCode, this);
}

// Sets default values
ASpaceObject::ASpaceObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpaceObject::BeginPlay()
{
	Super::BeginPlay();
	this->flyData->location = this->GetActorLocation();
	this->flyData->rotation = this->GetActorRotation();

}

void ASpaceObject::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	this->gameMode->xSpaceWorld->removeSpaceObject(this->worldCode);
}

// Called every frame
void ASpaceObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//this->applyFLyData();
	return;

	bool actionStatus = false;

	if (this->currentAction == nullptr) {
		if (this->actionQueue.IsEmpty()) {
			return;
		}

		// get new action
		this->actionQueue.Dequeue(this->currentAction);
	}

	actionStatus = this->currentAction->Do(DeltaTime);
	this->applyFLyData();

	// keep current action do
	if (actionStatus) {
		return;
	}

	// no actions here
	if (!actionStatus) {
		// destroy done action
//		onXActionDone.Broadcast(this->currentAction);
		this->currentAction = nullptr;
		return;
	}
}

void ASpaceObject::setMaxSpeed(float _maxSpeed)
{
	this->flyData->maxSpeed = _maxSpeed;
}

void ASpaceObject::applyFLyData()
{
	if (this->WasRecentlyRendered(0.25)) {
		this->SetActorLocation(this->flyData->location);
		this->SetActorRotation(this->flyData->rotation);
	}
}

void ASpaceObject::xTick(float DeltaTime)
{
	bool actionStatus = false;

	if (this->currentAction == nullptr) {
		if (this->actionQueue.IsEmpty()) {
			return;
		}

		// get new action
		this->actionQueue.Dequeue(this->currentAction);
	}

	actionStatus = this->currentAction->Do(DeltaTime);
	this->applyFLyData();

	// keep current action do
	if (actionStatus) {
		return;
	}

	// no actions here
	if (!actionStatus) {
		// destroy done action
//		onXActionDone.Broadcast(this->currentAction);
		this->currentAction = nullptr;
		return;
	}
}

