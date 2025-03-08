// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile/Ballprojectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Project2/Project2Character.h"
#include "Interface/HealthInterface.h"
#include "Component/HealthComponent.h"
#include <Kismet/GameplayStatics.h>


// Sets default values
ABallprojectile::ABallprojectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("Sphere Collision");
	SphereComponent->SetSphereRadius(35.f);
	// Åö×²Ô¤Éè
	SphereComponent->SetCollisionProfileName("Ball");
	// Ä£ÄâonHit
	SphereComponent->SetSimulatePhysics(true);
	SphereComponent->SetNotifyRigidBodyCollision(true);
	SphereComponent->OnComponentHit.AddDynamic(this, &ABallprojectile::OnHit);
	SetRootComponent(SphereComponent);

	


	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile Movement");
	ProjectileMovement->InitialSpeed = 1300.f;
}

// Called when the game starts or when spawned
void ABallprojectile::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(4.f);
}

// Called every frame
void ABallprojectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABallprojectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("ABallProjectile::OnHit"));
	///*AProject2Character* Player = Cast<AProject2Character>(OtherActor);
	//if (Player)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Hit"));
	//	Destroy();
	//}*/
	//if (OtherActor->Implements<UHealthInterface>())
	//{
	//	IHealthInterface::Execute_Damage(OtherActor);	// OtherActor->Damage_Implementation()
	//	Destroy();
	//}
	if (HitSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation(), 1, FMath::RandRange(0.4f, 1.3f), 0.f, HitSoundAttenuation);
	}

	AProject2Character* Player = Cast<AProject2Character>(OtherActor);
	if (Player != nullptr)
	{
		UHealthComponent* HealthComponent = Player->FindComponentByClass<UHealthComponent>();
		if (HealthComponent != nullptr)
		{
			HealthComponent->LoseHealth(Damage);
		}
		if (HitParticles != nullptr)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitParticles, GetActorTransform());
		}
		Destroy();
	}
}

