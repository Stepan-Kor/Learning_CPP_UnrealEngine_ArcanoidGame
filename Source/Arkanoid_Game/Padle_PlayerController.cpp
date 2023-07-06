// Fill out your copyright notice in the Description page of Project Settings.


#include "Padle_PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Paddle.h"
#include "Ball_CPP.h"

APadle_PlayerController::APadle_PlayerController()
{
}
void APadle_PlayerController::BeginPlay()
{
	TArray<AActor*>CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), 
		CameraActors);
	FViewTargetTransitionParams Camera_Parameters;
	SetViewTarget(CameraActors[0], Camera_Parameters);
	CreateBall();
}
void APadle_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	EnableInput(this);
	InputComponent->BindAxis("MoveHorizontal", this, &APadle_PlayerController::MoveHorizontal);
	InputComponent->BindAction("Launch", IE_Pressed, this, &APadle_PlayerController::LaunchBall);
}



void APadle_PlayerController::MoveHorizontal(float AxisValue)
{
	auto MyPawn = Cast<APaddle>(GetPawn());
	if (MyPawn) {
		MyPawn->MoveHorizontal(AxisValue);
	}
}

void APadle_PlayerController::LaunchBall()
{
	GEngine->AddOnScreenDebugMessage
	(-1, 4, FColor::Yellow, TEXT("Pressed Launch ball"));
	if (IsValid(Ball_Object)) {
		Ball_Object->Launch();
		GEngine->AddOnScreenDebugMessage
		(-1, 4, FColor::Yellow, TEXT("launching ball"));
	}
	else {
		GEngine->AddOnScreenDebugMessage
		(-1, 4, FColor::Yellow, TEXT("Controller dosnt have ball"));
		CreateBall();
	}
}

void APadle_PlayerController::CreateBall()
{
	if (!Ball_Object)Ball_Object = nullptr;
	if (Ball_Class) {
		//FActorSpawnParameters Spawn_Parameters;
		Ball_Object = GetWorld()->SpawnActor<ABall_CPP>
		(Ball_Class, Ball_Start_Location, FRotator(0, 0, 0)/*,Spawn_Parameters*/);
	}
	
}
