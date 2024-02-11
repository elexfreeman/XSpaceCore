// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Blueprint/UserWidget.h"

#include "../xspaceGameMode.h"
#include "../Data/LunerData.h"

#include "xBaseLuner.generated.h"


UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAA_on_cmd_action, FString, cmd);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAA_OnSelect, bool, on_select);

UCLASS()
class XSPACE_API AxBaseLuner : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AxBaseLuner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	AxspaceGameMode* gameMode = nullptr;
	bool isInit = false;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	////////////////

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "AA_Events")
		FAA_on_cmd_action on_cmd_action;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "AA_Events")
		FAA_OnSelect on_select;
	////////////////

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "info wiget")
	)
		UUserWidget* infoWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Space object name")
	)
		FString lunerName = TEXT("Base Luner");

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "World code XXX-123")
	)
		FString worldCode = TEXT("XXX-123");

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Space object name")
	)
		FLunerData lunerData;

	UFUNCTION(BlueprintCallable, Category = "AA", meta = (ToolTip = "Init space object"))
		void Init(FString shipName);
};
