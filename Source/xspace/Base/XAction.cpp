// Fill out your copyright notice in the Description page of Project Settings.


#include "XAction.h"

void UXAction::Init(FString _name, FString _worldCode)
{
	this->name = _name;
	this->worldCode = _worldCode;
}
bool UXAction::Do(float deltaTime)
{
	return false;
}
