// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball_CPP.generated.h"
class UProjectileMovementComponent;
UCLASS()
class ARKANOID_GAME_API ABall_CPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall_CPP();
	virtual void Launch();
	bool Launched;
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Ball;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UProjectileMovementComponent* ProjectileMovement;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
		UStaticMeshComponent* GetBall();
};
