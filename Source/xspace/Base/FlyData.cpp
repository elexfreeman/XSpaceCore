// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyData.h"

FVector UFlyData::GetActorForwardVector()
{
	return	UKismetMathLibrary::GetForwardVector(this->rotation);
}
