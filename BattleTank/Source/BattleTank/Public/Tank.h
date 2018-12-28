// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category=Setup)
	TSubclassOf<class AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category=Firing)
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category=Firing)
	float ReloadTimeInSeconds = 3.0;

	class UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0.0;

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category=Firing)
	void Fire();

	UFUNCTION(BlueprintCallable, Category=Setup)
	void SetBarrelReference(class UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category=Setup)
	void SetTurretReference(class UTankTurret* TurretToSet);

protected:
	class UTankAimingComponent* TankAimingComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
