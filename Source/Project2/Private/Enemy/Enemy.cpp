// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Enemy.h"
#include <Kismet/GameplayStatics.h>
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"
#include "Component/LookComponent.h"
#include "Projectile/Ballprojectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LookComponent = CreateDefaultSubobject<ULookComponent>(TEXT("Look Component"));
	LookComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	TargetCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	LookComponent->SetTarget(TargetCharacter);
}

void AEnemy::Fire()
{
	if (BallprojectileClass == nullptr)
	{
		return;
	}
	FVector ForwardVector = GetActorForwardVector();
	float SpawnDistance = 40.f;
	FVector SpawnLocation = GetActorLocation() + ForwardVector * SpawnDistance;
	//GetWorld()->SpawnActor<ABallprojectile>(BallprojectileClass, SpawnLocation, GetActorRotation());

	FTransform SpawnTransform(GetActorRotation(), SpawnLocation);
	// Projectile
	ABallprojectile* Projectile = GetWorld()->SpawnActorDeferred<ABallprojectile>(BallprojectileClass, SpawnTransform);

	Projectile->GetProjectileMovementComponent()->InitialSpeed = 2300;
	Projectile->FinishSpawning(SpawnTransform);


}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	bCanSeePlayer = LookComponent->CanSeeTarget();
	//看到时发射
	//if (bCanSeePlayer)
	//{
	//	//UE_LOG(LogTemp, Warning, TEXT("See"));
	//	Fire();  
	//}
	if (bCanSeePlayer != bPreviousCanSeePlayer)
	{
		if (bCanSeePlayer)
		{
			GetWorldTimerManager().SetTimer(FireTimerHandle, this, &AEnemy::Fire, FireInterval, true, FireDelay);
		}
		else
		{
			GetWorldTimerManager().ClearTimer(FireTimerHandle);
		}
	}
	bPreviousCanSeePlayer = bCanSeePlayer;
}

//bool AEnemy::LineTraceActor(const AActor* TargetActor)
//{
//	if (TargetActor == nullptr)
//	{
//		return false;
//	}
//	FVector Start = GetActorLocation();
//	FVector End = TargetActor->GetActorLocation();
//
//	if (CanSeeActor(TargetActor, Start, End))
//	{
//		FRotator DirectRotation = UKismetMathLibrary::FindLookAtRotation(Start, End);
//		SetActorRotation(DirectRotation);
//		return true;
//	}
//
//	return false;
//}

////画线
//bool AEnemy::CanSeeActor(const AActor* TargetActor, FVector Start, FVector End) const
//{
//	if (TargetActor == nullptr)
//	{
//		return false;
//	}
//	FHitResult Hit;
//	ECollisionChannel Channel = ECollisionChannel::ECC_Visibility;
//	//ECollisionChannel Channel = ECollisionChannel::ECC_GameTraceChannel1;
//
//	// 忽略玩家和敌人 (this)
//	FCollisionQueryParams QueryParams;
//	QueryParams.AddIgnoredActor(this);
//	QueryParams.AddIgnoredActor(TargetActor);
//
//
//	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, Channel, QueryParams);
//	//GetWorld()->LineTraceMultiByChannel(TArrayResult, Start, End, Channel, QueryParams);
//
//	DrawDebugLine(GetWorld(), Start, End, FColor::Cyan);
//
//	return !Hit.bBlockingHit;
//}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


