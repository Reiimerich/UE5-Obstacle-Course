// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingObstacle.generated.h"

UCLASS()
class OBSTACLECOURSE_API AMovingObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int32 MyInt = 99;

	UPROPERTY(EditAnywhere)
	int32 InputA = 14;

	UPROPERTY(EditAnywhere)
	int32 InputB = 16;

	UPROPERTY(EditAnywhere)
	int32 InputC = 0;

	UPROPERTY(EditAnywhere)
	float FloatA = 7.65;

	UPROPERTY(EditAnywhere)
	float FloatB = 11.86;

	UPROPERTY(EditAnywhere)
	float TotalFloat = 0;
};
