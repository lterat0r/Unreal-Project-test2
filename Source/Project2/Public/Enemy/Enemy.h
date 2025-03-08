// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

// BeginPlay ��ȡĿ��
// Tick ���LineTrace ת��
// Tick->LineTraceActor
// Tick->LineTraceActor->CanSeeActor const

class ULookComponent;
class ABallprojectile;

UCLASS()
class PROJECT2_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

	//bool LineTraceActor(const AActor* TargetActor); //��set  rotation������Ϊ const

	//bool CanSeeActor(const AActor* TargetActor, FVector Start, FVector End) const; //����û��ת�Ƕȿ�����const

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<ULookComponent> LookComponent;

	// SpawnActor
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABallprojectile> BallprojectileClass;

	bool bCanSeePlayer = false;

	bool bPreviousCanSeePlayer = false;

	FTimerHandle FireTimerHandle;

	float FireInterval = 3.f;
	float FireDelay = 0.5f;

	void Fire();

private:
	TObjectPtr<ACharacter> TargetCharacter;

	UPROPERTY(EditAnywhere)
	TArray<FHitResult> TArrayResult;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
