// Fill out your copyright notice in the Description page of Project Settings.


#include "xSpaceCoreEngine.h"

// Sets default values
AxSpaceCoreEngine::AxSpaceCoreEngine()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called every frame
void AxSpaceCoreEngine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UXAction* xAction = nullptr;

	if (!this->isThreadWork)
	{
		this->lastDeltaTime = DeltaTime;

		while (!this->actionQueueFinishWork.IsEmpty())
		{
			this->actionQueueFinishWork.Dequeue(xAction);
			this->gameMode->onXActionDone.Broadcast(xAction);
		}

		// DO update actor fly data
		for (const TPair<FString, AActor*>& pair : this->gameMode->xSpaceWorld->spaceMap)
		{
			(Cast<ASpaceObject>(pair.Value))->applyFLyData();
		}

		// check finish work actions
		this->isThreadWork = true;
	}
}

// Called when the game starts or when spawned
void AxSpaceCoreEngine::BeginPlay()
{
	Super::BeginPlay();
	this->gameMode = Cast<AxspaceGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	//this->spaceWorld = NewObject<USpaceWorld>();
	this->isLoop = true;
	this->MainEventLoop();
}
void AxSpaceCoreEngine::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	this->isLoop = true;
}

void AxSpaceCoreEngine::MainEventLoop()
{

	this->mainLoopFuture = Async(EAsyncExecution::Thread, [&]()
	{
		TQueue<UXAction*> actionQueueInProgress;
		TQueue<UXAction*> actionQueueForNextTick;
		UXAction* xAction = nullptr;
		bool isActionInProgress = false;

		while (isLoop)
		{
			if (!this->isThreadWork)
			{
				continue;
			}

			// Do action in progress
			while (!actionQueueInProgress.IsEmpty())
			{
				actionQueueInProgress.Dequeue(xAction);
				isActionInProgress = xAction->Do(this->lastDeltaTime);
				if (isActionInProgress)
				{
					actionQueueForNextTick.Enqueue(xAction);
				}
				else {
					this->actionQueueFinishWork.Enqueue(xAction);
				}
			}

			// put to next Tick
			while (!actionQueueForNextTick.IsEmpty())
			{
				actionQueueForNextTick.Dequeue(xAction);
				actionQueueInProgress.Enqueue(xAction);
			}


			while (!this->gameMode->actionQueueForWork.IsEmpty())
			{
				this->gameMode->actionQueueForWork.Dequeue(xAction);
				isActionInProgress = xAction->Do(this->lastDeltaTime);
				if (isActionInProgress)
				{
					actionQueueInProgress.Enqueue(xAction);
				}
				else {
					this->actionQueueFinishWork.Enqueue(xAction);
				}
			}
			this->isThreadWork = false;
		}
	});
}



