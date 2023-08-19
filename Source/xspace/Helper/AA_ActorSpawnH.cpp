// Fill out your copyright notice in the Description page of Project Settings.
#include "./AA_ActorSpawnH.h"



AActor* UAA_ActorSpawnH::fSpawnActorByClassName(UObject* vWorld, const FString& ClassName, FTransform oActorTransform)
{
	UClass* asActor = nullptr;

	AActor* oSpawnedActor = nullptr;

	UClass* FoundClass = LoadObject<UClass>(NULL, *ClassName, NULL, LOAD_None, NULL);
	bool bIsOk = false;

	if (FoundClass->IsChildOf(AActor::StaticClass()))
	{
		bIsOk = true;
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("isok FoundClass->IsChildOf(AActor::StaticClass()"));
	}
	else
	{
		FoundClass = nullptr;
		/* вот тут чтото */
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("fali load FoundClass  "));
	}

	if (bIsOk)
	{
		asActor = ((FoundClass)->IsChildOf(AActor::StaticClass())) ? FoundClass : NULL;
		bIsOk = (asActor != nullptr);
	}

	if (bIsOk)
	{
		AActor* oStartSpawnedActor = UGameplayStatics::BeginDeferredActorSpawnFromClass(
			vWorld,
			asActor,
			oActorTransform,
			ESpawnActorCollisionHandlingMethod::Undefined,
			((AActor*)nullptr));

		oSpawnedActor = UGameplayStatics::FinishSpawningActor(
			oStartSpawnedActor,
			oActorTransform);

		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("bIsOk SpawnActor"));
	}
	else
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("fali load bIsOk "));
	}

	return oSpawnedActor;
}




AActor* UAA_ActorSpawnH::fSpawnActorByClass(UObject* vWorld, TSubclassOf<AActor> ActorClass, FTransform oActorTransform)
{
	// спавним персонажа
	AActor* vActor = UGameplayStatics::BeginDeferredActorSpawnFromClass(
		vWorld,
		ActorClass,
		oActorTransform,
		ESpawnActorCollisionHandlingMethod::Undefined,
		((AActor*)nullptr)
	);

	UGameplayStatics::FinishSpawningActor(
		vActor,
		oActorTransform);

	return vActor;
}

TArray<FTransform> UAA_ActorSpawnH::fGetActorTransformLine(FVector in_vcStartPos, int32 nCount, FTransform in_vcCenter) {
	TArray<FTransform> resp;

	int32 k = -1;  // слева или справа
	int32 kX = 0; // отступ по X
	int32 n = 0;
	int32 offsetY = 200;
	int32 offsetX = 300;
	for (int32 i = 0; i < nCount; i++)
	{ 
		/* позиция */ 
		FRotator rot = UKismetMathLibrary::FindLookAtRotation(in_vcStartPos, in_vcCenter.GetLocation());
		FVector pos = in_vcStartPos + (rot.Quaternion().GetRightVector() * offsetY * k * n);

		k = -k; 

		/* масштаб */
		FVector scale;
		scale.X = 1;
		scale.Y = 1;
		scale.Z = 1;

		resp.Add(UKismetMathLibrary::MakeTransform(pos, rot, scale));

		if (k > 0)
		{
			n++;
		}
	}

	return resp;
}

AActor* UAA_ActorSpawnH::fSpawnAIByClassName(UWorld* vWorld, const FString& ClassName, FTransform oActorTransform)
{
	UClass* cl = LoadClass<APawn>(nullptr, *ClassName);
	//UClass* cl = StaticLoadClass(nullptr, *ClassName);
	TSubclassOf<APawn> ClassB;


	ClassB = cl->StaticClass(); // Performs a runtime check

	APawn* NewPawn = vWorld->SpawnActor<APawn>(cl);
	if (NewPawn != NULL)
	{
		NewPawn->SetActorTransform(oActorTransform);
		if (NewPawn->Controller == NULL)
		{	// NOTE: SpawnDefaultController ALSO calls Possess() to possess the pawn (if a controller is successfully spawned).
			NewPawn->SpawnDefaultController();
		}
	}


	//APawn* resp = UAIBlueprintHelperLibrary::SpawnAIFromClass(
	//	vWorld, 
	//	ClassB::StaticClass(),
	//	((UBehaviorTree*)nullptr), 
	//	oActorTransform.GetLocation(), FRotator(0.0f, 0.0f, 0.0f), false);

	return NewPawn;


}


AActor* UAA_ActorSpawnH::fSpawnAIByClass(UWorld* vWorld, TSubclassOf<AActor> ActorClass, FTransform oActorTransform)
{

	APawn* NewPawn = vWorld->SpawnActor<APawn>(ActorClass);
	if (NewPawn != NULL)
	{
		NewPawn->SetActorTransform(oActorTransform);
		if (NewPawn->Controller == NULL)
		{	// NOTE: SpawnDefaultController ALSO calls Possess() to possess the pawn (if a controller is successfully spawned).
			NewPawn->SpawnDefaultController();
		}
	}


	//APawn* resp = UAIBlueprintHelperLibrary::SpawnAIFromClass(
	//	vWorld, 
	//	ClassB::StaticClass(),
	//	((UBehaviorTree*)nullptr), 
	//	oActorTransform.GetLocation(), FRotator(0.0f, 0.0f, 0.0f), false);

	return NewPawn;


}
