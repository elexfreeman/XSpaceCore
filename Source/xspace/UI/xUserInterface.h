// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#define MAP_SCROLL_LEFT 1
#define MAP_SCROLL_RIGHT 2
#define MAP_SCROLL_UP 3
#define MAP_SCROLL_DOWN 4
#define MAP_ZOOM_IN 5
#define MAP_ZOOM_OUT 6

#define MAP_SCROLL_VALUE 30
#define MAP_ZOOM_VALUE 90

#define MAP_SCROLL_MULT_DEFAULT 1 
#define MAP_SCROLL_MULT_DELTA 0.05f 

#define MAP_ZOOM_MULT_DEFAULT 1 
#define MAP_ZOOM_MULT_DELTA 0.4f 

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "../xspaceGameMode.h"

#include "xUserInterface.generated.h"

UCLASS(Config = Game)
class XSPACE_API AxUserInterface : public APawn
{
	GENERATED_BODY()

protected:
	float scrollMultH = MAP_SCROLL_MULT_DEFAULT;
	float scrollMultV = MAP_SCROLL_MULT_DEFAULT;
	float scrollMultDelta = MAP_SCROLL_MULT_DELTA;

	float zoomMult = MAP_ZOOM_MULT_DEFAULT;
	float zoomMultDelta = MAP_ZOOM_MULT_DELTA;

public:
	// Sets default values for this actor's properties
	AxUserInterface();

	/** StaticMesh component that will be the visuals for our flying pawn */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* PlaneMesh;

	/** Spring arm that will offset the camera */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArm;

	/** Camera component that will be our viewpoint */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int inputStateH = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
	int inputStateV = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
	int inputStateZ = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
	AxspaceGameMode* gameMode = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Begin APawn overrides
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override; // Allows binding actions/axes to functions
	// End APawn overrides

	void ScrollUpInput();
	void ScrollDownInput();
	void ScrollLeftInput();
	void ScrollRightInput();
	void ZoomInInput();
	void ZoomOutInput();

	void ScrollUpInputR();
	void ScrollDownInputR();
	void ScrollLeftInputR();
	void ScrollRightInputR();
	void ZoomInInputR();
	void ZoomOutInputR();

	void ScrollStopInput();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	/** Returns PlaneMesh subobject **/
	FORCEINLINE class UStaticMeshComponent* GetPlaneMesh() const { return PlaneMesh; }
	/** Returns SpringArm subobject **/
	FORCEINLINE class USpringArmComponent* GetSpringArm() const { return SpringArm; }
	/** Returns Camera subobject **/
	FORCEINLINE class UCameraComponent* GetCamera() const { return Camera; }
};
