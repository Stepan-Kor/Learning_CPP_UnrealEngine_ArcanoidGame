// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"
#include <GameFramework/FloatingPawnMovement.h>
#include "Components/StaticMeshComponent.h" 
// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SM_Padle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("sdf"));
	SM_Padle->SetEnableGravity(false);
	SM_Padle->SetConstraintMode(EDOFMode::XZPlane);
	SM_Padle->SetCollisionProfileName(TEXT("PhysicsActor"));
	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("floating movement"));




}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APaddle::MoveHorizontal(float Axis)
{
	AddMovementInput(FVector(0, Axis, 0),1,false);
}

