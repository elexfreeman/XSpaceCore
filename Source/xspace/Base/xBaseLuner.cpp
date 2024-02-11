// Fill out your copyright notice in the Description page of Project Settings.


#include "xBaseLuner.h"

// Sets default values
AxBaseLuner::AxBaseLuner()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AxBaseLuner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AxBaseLuner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AxBaseLuner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AxBaseLuner::Init(
	FString _name
)
{
	this->gameMode = Cast<AxspaceGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	this->lunerName = _name;
	this->worldCode = this->gameMode->xNameGenerator->generate();
	this->gameMode->addSpaceObject(this->worldCode, this);

	UE_LOG(LogTemp, Warning,
		TEXT("Init sp class: %s, code: %s"), *(this->GetClass()->GetName()), *(this->worldCode)
	);

	this->isInit = true;
}
