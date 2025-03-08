// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ballprojectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class PROJECT2_API ABallprojectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABallprojectile();

	// The Sound
	UPROPERTY(EditAnywhere, category = "Damage")
	TObjectPtr<USoundBase> HitSound;

	UPROPERTY(EditAnywhere, category = "Damage")
	TObjectPtr<USoundAttenuation> HitSoundAttenuation;

	UPROPERTY(EditAnywhere, category = "Damage")
	TObjectPtr<UParticleSystem> HitParticles;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, category = "Damage")
	float Damage = 40.f;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "Ball", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> SphereComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "Ball", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FORCEINLINE UProjectileMovementComponent* GetProjectileMovementComponent() const { return ProjectileMovement; }

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
