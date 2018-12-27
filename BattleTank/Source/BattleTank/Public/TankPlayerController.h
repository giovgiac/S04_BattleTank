// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Project Includes
#include "Tank.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Crosshair")
	float CrossHairX = 0.5;

	UPROPERTY(EditDefaultsOnly, Category="Crosshair")
	float CrossHairY = 0.3333;

	UPROPERTY(EditDefaultsOnly, Category="Linetrace")
	float LineTraceRange = 1000000;

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

private:
	void AimTowardsCrosshair();

	ATank* GetControlledTank() const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
