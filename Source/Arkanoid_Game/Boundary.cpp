// Fill out your copyright notice in the Description page of Project Settings.


#include "Boundary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"
#include "Ball_CPP.h"
// Sets default values
ABoundary::ABoundary()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Box_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	RootComponent = Box_Collision;
}



void ABoundary::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Box_Collision->SetRelativeLocation(FVector(0, 0, 0));

}


// Called when the game starts or when spawned
// Called when the game starts or when spawned

inline void ABoundary::BeginPlay()
{
	Super::BeginPlay();
	Box_Collision->OnComponentBeginOverlap.AddDynamic(this, &ABoundary::OnOverlapBegin);
	//GEngine->AddOnScreenDebugMessage
	//GEngine->AddOnScreenDebugMessage(-1,2,FColor::Yellow,)
	//GE

}

void ABoundary::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage
	(-1, 4, FColor::Yellow, TEXT("Boudary had overlaped something"));
	if (OtherActor) {

		ABall_CPP* Temporal_Ball = Cast<ABall_CPP>(OtherActor);
		if (Temporal_Ball)Temporal_Ball->Destroy();

	}
}