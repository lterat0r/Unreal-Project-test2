// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ThirdPlayerController.h"
#include <HUD/RestartWidget.h>
#include <HUD/HealthWidget.h>
#include <HUD/ThirdHUD.h>

void AThirdPlayerController::ShowRestartWidget()
{
	if (RestartWidgetClass != nullptr)
	{
		SetPause(true);
		SetInputMode(FInputModeUIOnly());

		bShowMouseCursor = true;
		RestartWidget = CreateWidget<URestartWidget>(this, RestartWidgetClass);
		RestartWidget->AddToViewport();
	}
}

void AThirdPlayerController::HideRestartWidget()
{
	RestartWidget->RemoveFromParent();
	RestartWidget->Destruct();
	SetPause(false);
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}

void AThirdPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//if (HealthWidgetClass!=nullptr)
	//{
	//	HealthWidget = CreateWidget<UHealthWidget>(this, HealthWidgetClass);
	//	HealthWidget->AddToViewport();
	//	//HealthWidget->UpdateHealthPercent(1.f);
	//}
	ThirdHUD = Cast<AThirdHUD>(GetHUD());
	if (ThirdHUD != nullptr)
	{
		ThirdHUD->CreateHealthWidget();
	}
}

void AThirdPlayerController::UpdateHealthPercent(float HealthPercent)
{
	/*if (HealthWidget != nullptr)
	{
		HealthWidget->UpdateHealthPercent(HealthPercent);
	}*/
	if (ThirdHUD != nullptr)
	{
		ThirdHUD->UpdateHealth(HealthPercent);
	}

}


