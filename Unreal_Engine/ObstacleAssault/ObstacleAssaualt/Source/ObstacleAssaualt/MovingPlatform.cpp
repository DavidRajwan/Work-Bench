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
	
	StartLocation = GetActorLocation(); 

	UE_LOG(LogTemp, Display, TEXT("Configured Moved Distance: %f"), MovedDistance);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime); 

	
}

//Move the platform back and forth
void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (ShouldPlatformReturn())
	{
		//Flips the direction the platform moves
		FVector MoveDirection = PlatformVelocity.GetSafeNormal(); 
		StartLocation = StartLocation + MoveDirection * MovedDistance;
		SetActorLocation(StartLocation);  
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		//Moves the platform forward
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime); 
		SetActorLocation(CurrentLocation); 
	}
}

//Rotate a platform
void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

//Logic for if the platform should move
bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MovedDistance;
}

//Get the distance moved from the starting position
float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
	
}
	