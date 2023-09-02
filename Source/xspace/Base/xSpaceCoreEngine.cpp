// Fill out your copyright notice in the Description page of Project Settings.


#include "xSpaceCoreEngine.h"

// Sets default values
AxSpaceCoreEngine::AxSpaceCoreEngine()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AxSpaceCoreEngine::noThreadDo(float DeltaTime)
{
	//TQueue<UXAction*> actionQueueInProgress;
	//UXAction* xAction = nullptr;
	//bool isActionInProgress = false;

	//while (!this->gameMode->actionQueueForWork.IsEmpty())
	//{
	//	this->gameMode->actionQueueForWork.Dequeue(xAction);
	//	isActionInProgress = xAction->Do(DeltaTime);
	//	if (isActionInProgress)
	//	{
	//		actionQueueInProgress.Enqueue(xAction);
	//	}
	//	else {
	//		// broadcast finish action
	//		(Cast<ASpaceObject>(xAction->owner))->onXActionDone.Broadcast(xAction);
	//	}
	//}

	//// retrun actions in work
	//while (!actionQueueInProgress.IsEmpty())
	//{
	//	actionQueueInProgress.Dequeue(xAction);
	//	this->gameMode->actionQueueForWork.Enqueue(xAction);
	//}

	//for (const TPair<FString, AActor*>& pair : this->gameMode->xSpaceWorld->spaceMap)
	//{
	//	(Cast<ASpaceObject>(pair.Value))->applyFLyData();
	//}
}

void AxSpaceCoreEngine::threadDo(float DeltaTime)
{
	FString worldCode = TEXT("");
	UXAction* xAction = nullptr;

	if (!this->isThreadWork)
	{
		this->lastDeltaTime = DeltaTime;

		while (!this->objQueueFinishWork.IsEmpty())
		{
			this->objQueueFinishWork.Dequeue(worldCode);
			xAction = (Cast<ASpaceObject>(this->gameMode->xSpaceWorld->spaceMap[worldCode]))->currentAction;
			(Cast<ASpaceObject>(xAction->owner))->onXActionDone.Broadcast(xAction);
		}

		// DO update actor fly data
		for (const TPair<FString, AActor*>& pair : this->gameMode->xSpaceWorld->spaceMap)
		{
			(Cast<ASpaceObject>(pair.Value))->applyFLyData();
		}

		this->isThreadWork = true;
		//if (this->isNextTick)
		//{
		//	//TODO: aftrer next tick
		//	// start thread work
		//	this->isThreadWork = true;
		//	this->isNextTick = false;
		//}
		//else {
		//	this->isNextTick = true;
		//}
	}
}

// Called every frame
void AxSpaceCoreEngine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (this->isThreadsEnable)
	{
		this->threadDo(DeltaTime);
	}
	else
	{
		this->noThreadDo(DeltaTime);
	}

}

// Called when the game starts or when spawned
void AxSpaceCoreEngine::BeginPlay()
{
	Super::BeginPlay();
	this->gameMode = Cast<AxspaceGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	this->isLoop = true;
	if (this->isThreadsEnable) this->MainEventLoop();
}

void AxSpaceCoreEngine::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	this->isLoop = false;
	this->actionQueueFinishWork.Empty();
	this->gameMode->actionQueueForWork.Empty();
}

void AxSpaceCoreEngine::MainEventLoop()
{
	this->mainLoopFuture = Async(EAsyncExecution::Thread, [&]()
	{
		TQueue<FString> actionQueueInProgress;
		TQueue<FString> actionQueueForNextTick;

		UXAction* xAction = nullptr;

		FString worldCode = TEXT("");
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
				if (!isLoop) break;
				actionQueueInProgress.Dequeue(worldCode);

				xAction = (Cast<ASpaceObject>(this->gameMode->xSpaceWorld->spaceMap[worldCode]))->currentAction;
				isActionInProgress = xAction->Do(this->lastDeltaTime);

				if (isActionInProgress)
				{
					actionQueueForNextTick.Enqueue(worldCode);
				}
				else {
					this->objQueueFinishWork.Enqueue(worldCode);
				}
			}

			// put to next Tick
			while (!actionQueueForNextTick.IsEmpty())
			{
				if (!isLoop) break;
				actionQueueForNextTick.Dequeue(worldCode);
				actionQueueInProgress.Enqueue(worldCode);
			}


			while (!this->gameMode->objWithActiveActions.IsEmpty())
			{
				if (!isLoop) break;
				this->gameMode->objWithActiveActions.Dequeue(worldCode);

				xAction = (Cast<ASpaceObject>(this->gameMode->xSpaceWorld->spaceMap[worldCode]))->currentAction;
				isActionInProgress = xAction->Do(this->lastDeltaTime);

				if (isActionInProgress)
				{
					actionQueueInProgress.Enqueue(worldCode);
				}
				else {
					this->objQueueFinishWork.Enqueue(worldCode);
				}
			}
			this->isThreadWork = false;
		}
		actionQueueInProgress.Empty();
		actionQueueForNextTick.Empty();
	});
}



