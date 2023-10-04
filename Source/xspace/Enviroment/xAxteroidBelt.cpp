// Fill out your copyright notice in the Description page of Project Settings.


#include "xAxteroidBelt.h"

// Sets default values
AxAxteroidBelt::AxAxteroidBelt()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AxAxteroidBelt::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AxAxteroidBelt::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<FVector> AxAxteroidBelt::getLocationList()
{
	TArray<FVector> out;
	FVector v;

	int addMAX = 0;
	bool isDouble = true;

	for (int k = 0; k < this->spawnLocationList.Num(); k++)
	{
		for (int n = 0; n < this->maxCountInLocation; n++)
		{
			// find double
			v.X = FMath::RandRange(0, this->maxCountInLocation);
			v.Y = FMath::RandRange(0, this->maxCountInLocation);
			v.Z = FMath::RandRange(0, this->maxCountInLocation);
			v.X = this->spawnLocationList[k].X + (v.X*this->distanceBetween);
			v.Y = this->spawnLocationList[k].Y + (v.Y*this->distanceBetween);
			v.Z = this->spawnLocationList[k].Z + (v.Z*this->distanceBetween);
			out.Add(v);

		}
	}


	return out;
}

