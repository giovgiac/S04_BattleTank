// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

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

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerPawn);
}
