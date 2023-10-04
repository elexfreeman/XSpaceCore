// Fill out your copyright notice in the Description page of Project Settings.


#include "XActionDelay.h"

void UXActionDelay::Init(
	AActor* _owner,
	FString _worldCode,
	float _delayTime
)
{
	this->delayTime = _delayTime;
}

bool UXActionDelay::Do(float deltaTime)
{
	return false;
}
