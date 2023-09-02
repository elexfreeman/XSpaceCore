// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Async/Async.h"
#include "HAL/ThreadSafeBool.h"
#include "Containers/Queue.h"
#include "Kismet/GameplayStatics.h"

#include "../xspaceGameMode.h"
#include "./XAction.h"
#include "./SpaceObject.h"

#include "xSpaceCoreEngine.generated.h"

UCLASS()
class XSPACE_API AxSpaceCoreEngine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AxSpaceCoreEngine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	bool isNextTick = false;

	TQueue<UXAction*> actionQueueFinishWork;
	TQueue<FString> objQueueFinishWork;

	void MainEventLoop();

	bool isLoop = false;
	FThreadSafeBool isThreadWork;

	TFuture<void> mainLoopFuture = nullptr;

	float lastDeltaTime = 0;
	AxspaceGameMode* gameMode = nullptr;

	void noThreadDo(float DeltaTime);
	void threadDo(float DeltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		bool isThreadsEnable = true;
};
