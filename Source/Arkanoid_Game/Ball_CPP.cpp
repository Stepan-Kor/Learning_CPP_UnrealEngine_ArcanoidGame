// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball_CPP.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
ABall_CPP::ABall_CPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("sdf"));
	RootComponent = SM_Ball;
	SM_Ball->SetSimulatePhysics(true);
	SM_Ball->SetEnableGravity(false);
	SM_Ball->SetConstraintMode(EDOFMode::YZPlane);
	SM_Ball->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Ball->SetCollisionProfileName(TEXT("PhysicsActor"));
	SM_Ball->SetGenerateOverlapEvents(true);
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("new text projectile movement"));
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.1f;
	ProjectileMovement->Friction = 0;
	ProjectileMovement->Velocity.X = 0;

}

// Called when the game starts or when spawned
void ABall_CPP::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABall_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Launched) {
		FVector Velocity = SM_Ball->GetComponentVelocity();
		//Velocity /= Velocity.Size();
		//Velocity *= 250;
		//Velocity.ToText()
		Velocity.Normalize();
		
		Velocity *= 250;
		SM_Ball->SetPhysicsLinearVelocity(Velocity);
		float LenghtOfVector =  Velocity.Size();
		FString Text = FString::Printf(TEXT("Size %f"), LenghtOfVector);
		//FString::Printf(TEXT("sdf %f"), Velocity.ToText())
		GEngine->AddOnScreenDebugMessage(-1, .001, FColor::Yellow, Text);
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("World delta for current frame equals %f"), GetWorld()->TimeSeconds));

	}

}

UStaticMeshComponent* ABall_CPP::GetBall()
{
	return SM_Ball;
}

void ABall_CPP::Launch()
{
	if (!Launched) {
		Launched = true;
		SM_Ball->AddImpulse(FVector(0, FMath::RandRange(-250, 250), 100),FName(),true);
		//FMath::RandRange(-250, 250)
	}
}

