// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ThirdHUD.generated.h"

class UHealthWidget;

/**
 * 
 */
UCLASS()
class PROJECT2_API AThirdHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "HUD")
	TSubclassOf<UHealthWidget> HealthWidgetClass;

	UPROPERTY()
	TObjectPtr<UHealthWidget> WidgetInstance;

	void CreateHealthWidget();

	void UpdateHealth(float HealthPercent);
};
