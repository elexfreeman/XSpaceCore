// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Enum/FactoryModuleStateEnum.h"
#include "../Data/FactoryInOutData.h"
#include "xFactoryModule.generated.h"

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FA_work);

UCLASS()
class XSPACE_API AxFactoryModule : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AxFactoryModule();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	FTimerHandle factoryTimerHandle;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "AA_Events")
		FA_work on_work;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		float operationTime = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		TArray<FFactoryInOutData> input;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		TArray<FFactoryInOutData> output;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		FactoryModuleStateEnum state = FactoryModuleStateEnum::Iddle;

	void factoryTick();
};
