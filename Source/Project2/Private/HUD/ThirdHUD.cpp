// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/ThirdHUD.h"
#include "HUD/HealthWidget.h"

void AThirdHUD::CreateHealthWidget()
{
	APlayerController* PlayerController = GetOwningPlayerController();
	if (HealthWidgetClass != nullptr)
	{
		WidgetInstance = CreateWidget<UHealthWidget>(PlayerController, HealthWidgetClass);
		WidgetInstance->AddToViewport();
	}
}

void AThirdHUD::UpdateHealth(float HealthPercent)
{
	if (WidgetInstance != nullptr)
	{
		WidgetInstance->UpdateHealthPercent(HealthPercent);
	}
}
