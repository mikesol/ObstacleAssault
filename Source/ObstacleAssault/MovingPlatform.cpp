// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	FVector CurrentLocation = GetActorLocation();
	InitialYLocation = CurrentLocation.Y;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector CurrentLocation = GetActorLocation();
	if (CurrentLocation.Y > InitialYLocation + 1000.0)
	{
		YIsRight = false;
	}
	else if (CurrentLocation.Y < InitialYLocation - 1000.0)
	{
		YIsRight = true;
	}
	if (YIsRight)
	{
		CurrentLocation.Y = CurrentLocation.Y + (DeltaTime * 100.0);
	}
	else
	{
		CurrentLocation.Y = CurrentLocation.Y - (DeltaTime * 100.0);
	}
	SetActorLocation(CurrentLocation);
}
