// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

// Engine Includes
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

// Project Includes
#include "Tank.h"

void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (IsValid(PlayerTank))
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Found Player: %s"), *PlayerTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Can't Find Player Tank"));
	}
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!GetControlledTank())
		return;

	if (!GetPlayerTank())
		return;

	// TODO: Move Towards Player

	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

	// TODO: Fire if Ready
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerPawn);
}
