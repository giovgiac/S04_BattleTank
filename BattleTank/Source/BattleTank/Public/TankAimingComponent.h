// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UCLASS(ClassGroup=(Tank), meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);

	void SetBarrelReference(class UTankBarrel* BarrelToSet);

	void SetTurretReference(class UTankTurret* TurretToSet);

private:
	void MoveBarrelTo(FVector AimDirection);

private:
	class UTankBarrel* Barrel = nullptr;
	class UTankTurret* Turret = nullptr;
};
