// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/KismetMathLibrary.h"
#include "JsonUtilities/Public/JsonObjectConverter.h"

#include "FlyData.generated.h"

/**
 *
 */
UCLASS()
class XSPACE_API UFlyData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Current speed")
	)
		float currentSpeed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA_Fly", meta = (ToolTip = "Braking distances (m)")
	)
		float brakingDistances = 100.0f; // TODO: = f(massa)

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA_Fly", meta = (ToolTip = "Stop distances (m)")
	)
		float stopDistances = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA_Fly", meta = (ToolTip = "Braking speed")
	)
		float brakingPower = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA_Fly", meta = (ToolTip = "Acceleration power of speed")
	)
		float accelerationPower = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA_Fly", meta = (ToolTip = "Rotation power speed")
	)
		float rotationPower = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA_Fly", meta = (ToolTip = "Max speed (m/s)")
	)
		float maxSpeed = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Massa tonn")
	)
		float massa = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Volume m3")
	)
		float volume = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Radius m2")
	)
		float radius = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Directrion")
	)
		AActor* rootActor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		FRotator rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		FVector location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		FVector forwardVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		bool isVisible = true;

	UFUNCTION(BlueprintCallable, Category = "AA_Lib")
		FVector	GetActorForwardVector();

	UFUNCTION(BlueprintCallable, Category = "AA_Save")
		void setSaveData(FString _saveData);

	UFUNCTION(BlueprintCallable, Category = "AA_Save")
		FString getSaveData();
};
