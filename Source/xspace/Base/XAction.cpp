// Fill out your copyright notice in the Description page of Project Settings.


#include "XAction.h"

void UXAction::Init(FString _name)
{
	this->name = _name;
}
bool UXAction::Do(float deltaTime)
{
	return false;
}
