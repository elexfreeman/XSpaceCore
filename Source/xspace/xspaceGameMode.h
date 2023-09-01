// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/Actor.h"
#include "./Base/XAction.h"
#include "Async/Async.h"
#include "HAL/ThreadSafeBool.h"
#include "Containers/Queue.h"

#include "./Base/XNameGenerator.h"		
#include "./Base/SpaceWorld.h"		

#include "xspaceGameMode.generated.h"

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAA_OnAddSpaceObject, AActor*, spaceObject);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAA_OnSelectSpaceObject_listWiget, AActor*, spaceObject);

UCLASS(MinimalAPI)
class AxspaceGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


public:
	AxspaceGameMode();

	UPROPERTY(BlueprintAssignable, Category = "AA_Events")
		FAA_OnAddSpaceObject onAddSpaceObject;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "AA_Events")
		FAA_OnSelectSpaceObject_listWiget onSelectSpaceObject_listWiget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		UXNameGenerator* xNameGenerator = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		USpaceWorld* xSpaceWorld = nullptr;


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TQueue<UXAction*> actionQueueForWork;

	UFUNCTION(BlueprintCallable, Category = "AA")
		void addXAction(UXAction* _xAction);

	UFUNCTION(BlueprintCallable, Category = "AA")
		void addSpaceObject(FString _worldCode, AActor * spaceObject);
};



