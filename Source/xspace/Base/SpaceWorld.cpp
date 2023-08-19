// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceWorld.h"

void USpaceWorld::SetIsLoop(bool _isLoop)
{
	this->isLoop = _isLoop;
}

void  USpaceWorld::Init()
{
	this->isLoop = true;
}

void  USpaceWorld::UnInit()
{
	this->isLoop = false;
//	YourObject->ConditionalBeginDestroy();
}

FString USpaceWorld::addSpaceObject(ASpaceObject * spaceObject)
{
	FString out;
	this->objectCounter++;

	out = spaceObject->name + FString::FromInt(this->objectCounter);
	this->spaceMap.Add(out, spaceObject);

	spaceObject->spaceMapKey = out;

	return out;
}

int64 USpaceWorld::getCurrentTick()
{
	int64 _currentTimeStamp = FDateTime::Now().ToUnixTimestamp();
	int64 tick = _currentTimeStamp - this->lastTimeStamp;
	this->lastTimeStamp = _currentTimeStamp;
	return tick;
}


void USpaceWorld::MainEventLoop()
{
	this->mainLoopFuture = Async(EAsyncExecution::Thread, [&]()
	{
		int64 currentTick = this->getCurrentTick();
		while (isLoop)
		{
			currentTick = this->getCurrentTick();
			for (const TPair<FString, ASpaceObject*>& pair : this->spaceMap)
			{
				pair.Key;
				pair.Value;
				pair.Value->Tick(currentTick);
			}

		}
	});
}
