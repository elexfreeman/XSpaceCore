// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EngineUtils.h"
#include "Containers/Queue.h"
#include "./XAction.h"

#include "SpaceObject.generated.h"


UCLASS()
class XSPACE_API ASpaceObject : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	TQueue<UXAction*> actionQueue;
public:

	// Конструктор
	ASpaceObject();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Space object name")
	)
		FString name = TEXT("Space object");

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Massa tonn")
	)
		float massa = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Volume m3")
	)
		float volume = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Coord")
	)
		FVector coord = FVector(0, 0, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Directrion")
	)
		FVector direction = FVector(0, 0, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Space map key")
	)
		FString spaceMapKey = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Currren running action")
	)
		UXAction* currentAction = nullptr;
public:

	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Inner Core tick"))
		void Init(
			UPARAM(DisplayName = "Name") FString _name,
			UPARAM(DisplayName = "Massa") float _massa,
			UPARAM(DisplayName = "Volume m3") float _volume,
			UPARAM(DisplayName = "Coord ") FVector _coord,
			UPARAM(DisplayName = "Direction ") FVector _direction
		);
};
