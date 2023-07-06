// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "Ball_CPP.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SM_Brik = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Brik"));
	SM_Brik->SetNotifyRigidBodyCollision(true);
	
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	SM_Brik->OnComponentHit.AddDynamic(this, &ABrick::Brik_Hit);
	
	
}

void ABrick::Brik_Hit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (!Hited_by_Ball) {
		auto Temporal_Ball = Cast<ABall_CPP>(OtherActor);
		if (Temporal_Ball) {
			Hited_by_Ball = true;
			//FVector Ball_Velocity = Temporal_Ball->GetVelocity()*Speed_Modifier;
			//Temporal_Ball->GetBall()->SetPhysicsLinearVelocity(Ball_Velocity,true);
			FTimerHandle UnusedHandle;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrick::DestroyBrik, 0.01);
			GEngine->AddOnScreenDebugMessage
			(-1, 4, FColor::Yellow, TEXT("Brik hited"));
		}
	}
}

void ABrick::DestroyBrik()
{
	this->Destroy();
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

