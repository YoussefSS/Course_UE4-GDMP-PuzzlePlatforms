// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority()) // On Server
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
	
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority()) // On server
	{
		FVector Location = GetActorLocation();
		FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation); // Transform goes from local to global, inverse transform goes from global to local
		FVector Direction = (GlobalTargetLocation - Location).GetSafeNormal();
		Location += Speed * DeltaTime * Direction;
		SetActorLocation(Location);
	}
}
