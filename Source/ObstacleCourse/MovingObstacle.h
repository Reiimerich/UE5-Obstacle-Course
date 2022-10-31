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

private:

	UPROPERTY(EditAnywhere, Category = "Obstacle Properties")
	FVector ObstacleVelocity = FVector(100, 0, 0);
	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category = "Obstacle Properties")
	float MoveDistance = 100;

	void RotatePlatform(float DeltaTime);
	void MovePlatform(float DeltaTime);
	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;
};
