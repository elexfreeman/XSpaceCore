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

void USpaceWorld::addSpaceObject(FString key, AActor* spaceObject)
{
	this->objectCounter++;
	this->spaceMap.Add(key, spaceObject);
}

void USpaceWorld::removeSpaceObject(FString key)
{
	this->spaceMap.Remove(key);
}

//int64 USpaceWorld::getCurrentTick()
//{
//	int64 _currentTimeStamp = FDateTime::Now().ToUnixTimestamp();
//	int64 tick = _currentTimeStamp - this->lastTimeStamp;
//	this->lastTimeStamp = _currentTimeStamp;
//	return tick;
//}
//
//
//void USpaceWorld::MainEventLoop()
//{
//	this->mainLoopFuture = Async(EAsyncExecution::Thread, [&]()
//	{
//		int64 currentTick = this->getCurrentTick();
//		while (isLoop)
//		{
//			currentTick = this->getCurrentTick();
//			for (const TPair<FString, ASpaceObject*>& pair : this->spaceMap)
//			{
//				pair.Key;
//				pair.Value;
//				pair.Value->Tick(currentTick);
//			}
//
//		}
//	});
//}
