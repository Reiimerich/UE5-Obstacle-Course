// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingObstacle.h"

// Sets default values
AMovingObstacle::AMovingObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingObstacle::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingObstacle::MovePlatform(float DeltaTime)
{
	if(ShouldPlatformReturn())
	{
		FVector MoveDirection = ObstacleVelocity.GetSafeNormal();
		StartLocation += MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		ObstacleVelocity = -ObstacleVelocity;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation += ObstacleVelocity * DeltaTime;
		SetActorLocation(CurrentLocation);
	}
}

void AMovingObstacle::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

float AMovingObstacle::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

bool AMovingObstacle::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MoveDistance;
}


