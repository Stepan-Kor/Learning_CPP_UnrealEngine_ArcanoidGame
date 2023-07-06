// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"

UCLASS()
class ARKANOID_GAME_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* SM_Brik;
	//UPROPERTY() UBoxComponent* Box;
	float Speed_Modifier=1.05;
	UFUNCTION()  void Brik_Hit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	void DestroyBrik();
	bool Hited_by_Ball;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
