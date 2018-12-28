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


}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (ControlledTank && PlayerTank)
	{
		// TODO: Move Towards Player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire(); // TODO: Limit Firing Rate
	}
}

