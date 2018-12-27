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
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

private:
	void AimTowardsCrosshair();

	ATank* GetControlledTank() const;

	bool GetSightRayHitLocation(FVector * OutHitLocation) const;
};
