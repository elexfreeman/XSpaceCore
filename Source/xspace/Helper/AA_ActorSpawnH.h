// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

#include "AA_ActorSpawnH.generated.h"

/**
 * Для разнообразного спавна акторов и персонажей
 */
UCLASS()
class XSPACE_API UAA_ActorSpawnH : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "AA_Lib", Meta = (ToolTip = "Спавнит актора"))
		AActor* fSpawnActorByClassName(UObject* vWorld, const FString& ClassName, FTransform oActorTransform);

	UFUNCTION(BlueprintCallable, Category = "AA_Lib", Meta = (ToolTip = "Спавнит актора"))
		AActor* fSpawnActorByClass(UObject* vWorld, TSubclassOf<AActor> ActorClass, FTransform oActorTransform);
	
	UFUNCTION(BlueprintCallable, Category = AA, meta = (ToolTip = "Для спавна акторов в линию"))
		TArray<FTransform> fGetActorTransformLine(FVector in_vcStartPos, int32 nCount, FTransform in_vcCenter);

	UFUNCTION(BlueprintCallable, Category = "AA_Lib", Meta = (ToolTip = "Спавнит AI"))
		AActor* fSpawnAIByClassName(UWorld* vWorld, const FString& ClassName, FTransform oActorTransform);

	UFUNCTION(BlueprintCallable, Category = "AA_Lib", Meta = (ToolTip = "Спавнит AI по классу"))
		AActor* fSpawnAIByClass(UWorld* vWorld, TSubclassOf<AActor> ActorClass, FTransform oActorTransform);

};
