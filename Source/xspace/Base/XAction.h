// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Enum/XActionStateEnum.h"
#include "XAction.generated.h"

/**
 *
 */
UCLASS()
class XSPACE_API UXAction : public UObject
{
	GENERATED_BODY()

protected:
	bool isInit = false;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "Action name")
	)
		FString name = TEXT("Space object");;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "World code AAA-000")
	)
		FString worldCode = TEXT("AAA-000");

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "AA", meta = (ToolTip = "State")
	)
		XActionStateEnum state = XActionStateEnum::Run;

	void Init(FString _name, FString _worldCode);

	UFUNCTION(BlueprintCallable, Category = "AA_Lib", Meta = (ToolTip = "Do action. If done return false"))
		virtual	bool Do(float deltaTime);

};
