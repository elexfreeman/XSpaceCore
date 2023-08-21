// Fill out your copyright notice in the Description page of Project Settings.


#include "XAsteroid.h"


void AXAsteroid::BeginPlay()
{
	Super::BeginPlay();

	this->xActionAsteroidRotate = NewObject<UXActionAsteroidRotate>();
	this->xActionAsteroidRotate->Init(this);

	this->actionQueue.Enqueue(this->xActionAsteroidRotate);
}

void AXAsteroid::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
}
