// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"

#include "SpaceWorld.generated.h"

/**
 *
 */
UCLASS()
class XSPACE_API USpaceWorld : public UObject
{
	GENERATED_BODY()

private:
	int objectCounter = 0;
	int64 lastTimeStamp = 0;

public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "World objects")
	)
		TMap<FString, AActor*> spaceMap;

//	TFuture<void> mainLoopFuture;
	bool isLoop = false;

	//void MainEventLoop();

	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Innter Core tick"))
		void SetIsLoop(bool _isLoop);

	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Init X core"))
		void Init();

	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Stop X core"))
		void UnInit();

	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Add space object"))
		void addSpaceObject(FString key, AActor* spaceObject);

	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Add space object"))
		void removeSpaceObject(FString key);
};
