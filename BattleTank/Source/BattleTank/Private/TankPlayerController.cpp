// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (IsValid(ControlledTank))
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possessing %s"), *ControlledTank->GetName());
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Not Possessing a Tank"));
	}
}

void ATankPlayerController::Tick(float DeltaSeconds) 
{
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
		return;

	FVector HitLocation;
	if (GetSightRayHitLocation(&HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
		// Tell Controlled Tank to Aim At This Point
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

bool ATankPlayerController::GetSightRayHitLocation(FVector * OutHitLocation) const
{
	*OutHitLocation = FVector(1.0f);
	return true;
}
