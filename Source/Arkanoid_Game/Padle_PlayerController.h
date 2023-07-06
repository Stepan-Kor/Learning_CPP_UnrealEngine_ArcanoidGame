// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Ball_CPP.h"
#include "Padle_PlayerController.generated.h"


/**
 * 
 */
UCLASS()
class ARKANOID_GAME_API APadle_PlayerController : public APlayerController
{
	GENERATED_BODY()
		APadle_PlayerController();
	UFUNCTION() virtual void SetupInputComponent() override;
protected:
	virtual void BeginPlay() override;
	void MoveHorizontal(float AxisValue);
	ABall_CPP* Ball_Object;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall_CPP> Ball_Class;
	FVector Ball_Start_Location= FVector(0,0,40);
	void CreateBall();
public:
	void LaunchBall();

};
