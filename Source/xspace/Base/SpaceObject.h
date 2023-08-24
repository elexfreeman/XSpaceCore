// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "Containers/Queue.h"
#include "./XAction.h"
#include "./FlyData.h"
#include "../xspaceGameMode.h"

#include "SpaceObject.generated.h"


UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAA_OnXActionDone, UXAction*, uXAction);

UCLASS()
class XSPACE_API ASpaceObject : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	AxspaceGameMode* gameMode = nullptr;

	TQueue<UXAction*> actionQueue;
	bool isInit = false;


	UPROPERTY(BlueprintAssignable, Category = "AA_Events")
		FAA_OnXActionDone onXActionDone;

public:

	// Конструктор
	ASpaceObject();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Fly data params")
	)
		UFlyData* flyData = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Space object name")
	)
		FString name = TEXT("Space object");

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Space object name")
	)
		FString worldCode = TEXT("XXX-123");


	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Space map key")
	)
		FString spaceMapKey = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Currren running action")
	)
		UXAction* currentAction = nullptr;
public:

		void Init(FString _name);

	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Set max speed"))
		void setMaxSpeed(float _maxSpeed);
};
