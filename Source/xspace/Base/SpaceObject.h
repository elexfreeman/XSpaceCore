// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "Containers/Queue.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "JsonUtilities/Public/JsonObjectConverter.h"

#include "./XBaseSpaceObject.h"

#include "./XAction.h"
#include "./FlyData.h"
#include "../xspaceGameMode.h"

#include "SpaceObject.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(AA_SpaceObject, Log, All);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAA_OnXActionDone, UXAction*, uXAction);

UCLASS()
class XSPACE_API ASpaceObject : public AXBaseSpaceObject
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	AxspaceGameMode* gameMode = nullptr;

	TQueue<UXAction*> actionQueue;
	bool isInit = false;



public:
	// Конструктор
	ASpaceObject();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintAssignable, Category = "AA_Events")
		FAA_OnXActionDone onXActionDone;

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
		Category = "AA", meta = (ToolTip = "Currren running action")
	)
		UXAction* currentAction = nullptr;

	/** StaticMesh component that will be the visuals for our flying pawn */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* PlaneMesh;

	/** Spring arm that will offset the camera */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArm;

	/** Camera component that will be our viewpoint */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;

	void Init(FString _name);

	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Set max speed"))
		void setMaxSpeed(float _maxSpeed);

	UFUNCTION(BlueprintCallable, Category = "AA")
		void applyFLyData();

	void xTick(float DeltaTime);

	FString getSaveData();

	void showInfoModal();
};
