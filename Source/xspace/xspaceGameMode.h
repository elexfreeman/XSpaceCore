// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/Actor.h"
#include "./Base/XAction.h"
#include "Async/Async.h"
#include "HAL/ThreadSafeBool.h"
#include "Containers/Queue.h"

#include "./Base/XNameGenerator.h"		
#include "./Base/SpaceWorld.h"
#include "./Subsystems/XSaveGameSubsystem.h"

#include "xspaceGameMode.generated.h"

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAA_OnAddSpaceObject, AActor*, spaceObject);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAA_OnAddObjWithActiveAction, FString, _worldKey);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAA_OnSelectSpaceObject_listWiget, AActor*, spaceObject);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAA_OnFollowTarget_listWiget, AActor*, spaceObject);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAA_OnUnFollowTarget_listWiget);


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

	UPROPERTY(BlueprintAssignable, Category = "AA_Events")
		FAA_OnAddObjWithActiveAction onAddObjWithActiveAction;

	//++++ list widgit
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "AA_Events")
		FAA_OnSelectSpaceObject_listWiget onSelectSpaceObject_listWiget;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "AA_Events")
		FAA_OnFollowTarget_listWiget onFollowTarget_listWiget;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "AA_Events")
		FAA_OnUnFollowTarget_listWiget onUnFollowTarget_listWiget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		AActor* followTarget_listWget = nullptr;
	//---- list widgit

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		UXNameGenerator* xNameGenerator = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		USpaceWorld* xSpaceWorld = nullptr;


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TQueue<UXAction*> actionQueueForWork;

	UFUNCTION(BlueprintCallable, Category = "AA")
		void addXAction(UXAction* _xAction);

	TQueue<FString> objWithActiveActions;

	UFUNCTION(BlueprintCallable, Category = "AA")
		void addObjWithActiveAction(FString _worldKey);

	UFUNCTION(BlueprintCallable, Category = "AA")
		void addSpaceObject(FString _worldCode, AActor * spaceObject);
};



