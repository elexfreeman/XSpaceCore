// Fill out your copyright notice in the Description page of Project Settings.

#include "./SpaceObject.h"

DEFINE_LOG_CATEGORY(AA_SpaceObject);

void ASpaceObject::Init(
	FString _name
)
{
	this->gameMode = Cast<AxspaceGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	this->name = _name;
	this->flyData = NewObject<UFlyData>();
	this->flyData->rootActor = this;


	this->worldCode = this->gameMode->xNameGenerator->generate();

	this->gameMode->addSpaceObject(this->worldCode, this);

	UE_LOG(AA_SpaceObject, Warning,
		TEXT("Init sp class: %s, code: %s"), *(this->GetClass()->GetName()), *(this->worldCode)
	);
	this->isInit = true;
}

// Sets default values
ASpaceObject::ASpaceObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> PlaneMesh;
		FConstructorStatics()
			: PlaneMesh(TEXT("/Game/XCore/Meshes/default.default"))
		{
		}

	};
	static FConstructorStatics ConstructorStatics;

	// Create static mesh component
	PlaneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaneMesh0"));
	PlaneMesh->SetStaticMesh(ConstructorStatics.PlaneMesh.Get());	// Set static mesh
	PlaneMesh->SetHiddenInGame(true);
	RootComponent = PlaneMesh;

	// Create a spring arm component
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm0"));
	SpringArm->SetupAttachment(RootComponent);	// Attach SpringArm to RootComponent
	SpringArm->TargetArmLength = 160.0f; // The camera follows at this distance behind the character	
	SpringArm->SocketOffset = FVector(0.f, 0.f, 60.f);
	SpringArm->bEnableCameraLag = false;	// Do not allow camera to lag
	SpringArm->CameraLagSpeed = 15.f;

	// Create camera component 
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera0"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);	// Attach the camera
	Camera->bUsePawnControlRotation = false; // Don't rotate camera with controller

}

// Called when the game starts or when spawned
void ASpaceObject::BeginPlay()
{
	Super::BeginPlay();
	if (this->isInit)
	{
		this->flyData->location = this->GetActorLocation();
		this->flyData->rotation = this->GetActorRotation();
	}
}

void ASpaceObject::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (this->isInit) this->gameMode->xSpaceWorld->removeSpaceObject(this->worldCode);
}

// Called every frame
void ASpaceObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//this->applyFLyData();

//	bool actionStatus = false;
//
//	if (this->currentAction == nullptr) {
//		if (this->actionQueue.IsEmpty()) {
//			return;
//		}
//
//		// get new action
//		this->actionQueue.Dequeue(this->currentAction);
//	}
//
//	actionStatus = this->currentAction->Do(DeltaTime);
//	this->applyFLyData();
//
//	// keep current action do
//	if (actionStatus) {
//		return;
//	}
//
//	// no actions here
//	if (!actionStatus) {
//		// destroy done action
////		onXActionDone.Broadcast(this->currentAction);
//		this->currentAction = nullptr;
//		return;
//	}
}

void ASpaceObject::setMaxSpeed(float _maxSpeed)
{
	this->flyData->maxSpeed = _maxSpeed;
}

void ASpaceObject::applyFLyData()
{
	if (this->WasRecentlyRendered(0.25)) {
		this->SetActorLocation(this->flyData->location);
		this->SetActorRotation(this->flyData->rotation);
	}
}

void ASpaceObject::xTick(float DeltaTime)
{
	bool actionStatus = false;

	if (this->currentAction == nullptr) {
		if (this->actionQueue.IsEmpty()) {
			return;
		}

		// get new action
		this->actionQueue.Dequeue(this->currentAction);
	}

	actionStatus = this->currentAction->Do(DeltaTime);
	this->applyFLyData();

	// keep current action do
	if (actionStatus) {
		return;
	}

	// no actions here
	if (!actionStatus) {
		// destroy done action
//		onXActionDone.Broadcast(this->currentAction);
		this->currentAction = nullptr;
		return;
	}
}

FString ASpaceObject::getSaveData()
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField("name", this->GetName());
	JsonObject->SetStringField("worldCode", this->worldCode);
	JsonObject->SetStringField("className", this->GetClass()->GetName());
	JsonObject->SetStringField("flyData", this->flyData->getSaveData());
	if (this->currentAction != nullptr)
	{
		JsonObject->SetStringField("currentAction", this->currentAction->getSaveData());
	}
	else
	{
		JsonObject->SetStringField("currentAction", TEXT("{\"name\":\"null\"}"));
	}

	FString OutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	return OutputString;
}

void ASpaceObject::showInfoModal()
{
}

