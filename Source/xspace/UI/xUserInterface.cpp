// Fill out your copyright notice in the Description page of Project Settings.


#include "xUserInterface.h"

#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/World.h"

#include "Engine/StaticMesh.h"

// Sets default values
AxUserInterface::AxUserInterface()
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
	RootComponent = PlaneMesh;

	// Create a spring arm component
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm0"));
	SpringArm->SetupAttachment(RootComponent);	// Attach SpringArm to RootComponent
	SpringArm->TargetArmLength = 360.0f; // The camera follows at this distance behind the character	
	SpringArm->SocketOffset = FVector(0.f, 0.f, 60.f);
	SpringArm->bEnableCameraLag = false;	// Do not allow camera to lag
	SpringArm->CameraLagSpeed = 15.f;

	// Create camera component 
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera0"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);	// Attach the camera
	Camera->bUsePawnControlRotation = false; // Don't rotate camera with controller
}

// Called when the game starts or when spawned
void AxUserInterface::BeginPlay()
{
	Super::BeginPlay();

	this->gameMode = Cast<AxspaceGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

// Called every frame
void AxUserInterface::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector location = this->GetActorLocation();

	if (this->inputStateH) this->scrollMultH += this->scrollMultDelta;
	if (this->inputStateV) this->scrollMultV += this->scrollMultDelta;

	if (this->inputStateH == MAP_SCROLL_LEFT)
	{
		location.Y -= MAP_SCROLL_VALUE * this->scrollMultH;
		this->SetActorLocation(location);
		this->gameMode->onUnFollowTarget_listWiget.Broadcast();
	}

	if (this->inputStateH == MAP_SCROLL_RIGHT)
	{
		location.Y += MAP_SCROLL_VALUE * this->scrollMultH;
		this->SetActorLocation(location);
		this->gameMode->onUnFollowTarget_listWiget.Broadcast();
	}

	if (this->inputStateV == MAP_SCROLL_UP)
	{
		location.X += MAP_SCROLL_VALUE * this->scrollMultV;
		this->SetActorLocation(location);
		this->gameMode->onUnFollowTarget_listWiget.Broadcast();
	}

	if (this->inputStateV == MAP_SCROLL_DOWN)
	{
		location.X -= MAP_SCROLL_VALUE * this->scrollMultV;
		this->SetActorLocation(location);
		this->gameMode->onUnFollowTarget_listWiget.Broadcast();
	}

}

void AxUserInterface::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Check if PlayerInputComponent is valid (not NULL)
	check(PlayerInputComponent);

	// Bind our control axis' to callback functions
//	PlayerInputComponent->BindAxis("navMenuTop", this, &AxUserInterface::MoveUpInput);
//	PlayerInputComponent->BindAxis("navMenuLeft", this, &AxUserInterface::MoveRightInput);

	PlayerInputComponent->BindAction("MAP_SCROLL_LEFT", IE_Pressed, this, &AxUserInterface::ScrollLeftInput);
	PlayerInputComponent->BindAction("MAP_SCROLL_RIGHT", IE_Pressed, this, &AxUserInterface::ScrollRightInput);
	PlayerInputComponent->BindAction("MAP_SCROLL_UP", IE_Pressed, this, &AxUserInterface::ScrollUpInput);
	PlayerInputComponent->BindAction("MAP_SCROLL_DOWN", IE_Pressed, this, &AxUserInterface::ScrollDownInput);
	PlayerInputComponent->BindAction("MAP_ZOOM_IN", IE_Pressed, this, &AxUserInterface::ZoomInInput);
	PlayerInputComponent->BindAction("MAP_ZOOM_OUT", IE_Pressed, this, &AxUserInterface::ZoomOutInput);

	PlayerInputComponent->BindAction("MAP_SCROLL_LEFT", IE_Released, this, &AxUserInterface::ScrollLeftInputR);
	PlayerInputComponent->BindAction("MAP_SCROLL_RIGHT", IE_Released, this, &AxUserInterface::ScrollRightInputR);
	PlayerInputComponent->BindAction("MAP_SCROLL_UP", IE_Released, this, &AxUserInterface::ScrollUpInputR);
	PlayerInputComponent->BindAction("MAP_SCROLL_DOWN", IE_Released, this, &AxUserInterface::ScrollDownInputR);
	//	PlayerInputComponent->BindAction("MAP_ZOOM_IN", IE_Released, this, &AxUserInterface::ScrollStopInput);
	//	PlayerInputComponent->BindAction("MAP_ZOOM_OUT", IE_Released, this, &AxUserInterface::ScrollStopInput);
}

void AxUserInterface::ScrollRightInput()
{
	this->inputStateH = MAP_SCROLL_RIGHT;
	this->scrollMultH = MAP_SCROLL_MULT_DEFAULT;
}

void AxUserInterface::ScrollLeftInput()
{
	this->inputStateH = MAP_SCROLL_LEFT;
	this->scrollMultH = MAP_SCROLL_MULT_DEFAULT;
}

void AxUserInterface::ScrollDownInput()
{
	this->inputStateV = MAP_SCROLL_DOWN;
	this->scrollMultV = MAP_SCROLL_MULT_DEFAULT;
}

void AxUserInterface::ScrollUpInput()
{
	this->inputStateV = MAP_SCROLL_UP;
	this->scrollMultV = MAP_SCROLL_MULT_DEFAULT;
}

void AxUserInterface::ZoomInInput()
{
	if (this->inputStateZ == MAP_ZOOM_IN)
	{
		this->zoomMult += this->zoomMultDelta;
	}
	else
	{
		this->zoomMult = MAP_ZOOM_MULT_DEFAULT;
	}

	this->inputStateZ = MAP_ZOOM_IN;
	FVector location = this->GetActorLocation();
	location.Z -= MAP_ZOOM_VALUE * this->zoomMult;
	this->SetActorLocation(location);
}

void AxUserInterface::ZoomOutInput()
{
	if (this->inputStateZ == MAP_ZOOM_OUT)
	{
		this->zoomMult += this->zoomMultDelta;
	}
	else
	{
		this->zoomMult = MAP_ZOOM_MULT_DEFAULT;
	}

	this->inputStateZ = MAP_ZOOM_OUT;
	FVector location = this->GetActorLocation();
	location.Z += MAP_ZOOM_VALUE * this->zoomMult;
	this->SetActorLocation(location);
}



void AxUserInterface::ScrollRightInputR()
{
	if (this->inputStateH == MAP_SCROLL_RIGHT)
		this->inputStateH = 0;
}

void AxUserInterface::ScrollLeftInputR()
{
	if (this->inputStateH == MAP_SCROLL_LEFT)
		this->inputStateH = 0;
}

void AxUserInterface::ScrollDownInputR()
{
	if (this->inputStateV == MAP_SCROLL_DOWN)
		this->inputStateV = 0;
}

void AxUserInterface::ScrollUpInputR()
{
	if (this->inputStateV == MAP_SCROLL_UP)
		this->inputStateV = 0;
}

void AxUserInterface::ZoomInInputR()
{
	//	this->inputState = MAP_ZOOM_IN;
}

void AxUserInterface::ZoomOutInputR()
{
	//	this->inputState = MAP_ZOOM_OUT;
}

void AxUserInterface::ScrollStopInput()
{
}
