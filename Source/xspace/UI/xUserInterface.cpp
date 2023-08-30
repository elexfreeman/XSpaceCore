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

}

// Called every frame
void AxUserInterface::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, FString::Printf(TEXT("state = %d"), this->inputState));
	FVector location = this->GetActorLocation();

	if (this->inputState == MAP_SCROLL_LEFT)
	{
		location.Y -= 10;
		this->SetActorLocation(location);
	}

	if (this->inputState == MAP_SCROLL_RIGHT)
	{
		location.Y += 10;
		this->SetActorLocation(location);
	}

	if (this->inputState == MAP_SCROLL_UP)
	{
		location.X += 10;
		this->SetActorLocation(location);
	}

	if (this->inputState == MAP_SCROLL_DOWN)
	{
		location.X -= 10;
		this->SetActorLocation(location);
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

	PlayerInputComponent->BindAction("MAP_SCROLL_LEFT", IE_Released, this, &AxUserInterface::ScrollStopInput);
	PlayerInputComponent->BindAction("MAP_SCROLL_RIGHT", IE_Released, this, &AxUserInterface::ScrollStopInput);
	PlayerInputComponent->BindAction("MAP_SCROLL_UP", IE_Released, this, &AxUserInterface::ScrollStopInput);
	PlayerInputComponent->BindAction("MAP_SCROLL_DOWN", IE_Released, this, &AxUserInterface::ScrollStopInput);
}

void AxUserInterface::ScrollRightInput()
{
	this->inputState = MAP_SCROLL_RIGHT;
}

void AxUserInterface::ScrollLeftInput()
{
	this->inputState = MAP_SCROLL_LEFT;
}

void AxUserInterface::ScrollDownInput()
{
	this->inputState = MAP_SCROLL_DOWN;
}

void AxUserInterface::ScrollUpInput()
{
	this->inputState = MAP_SCROLL_UP;
}

void AxUserInterface::ScrollStopInput()
{
	this->inputState = 0;
}
