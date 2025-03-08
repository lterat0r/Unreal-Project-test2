// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ThirdPlayerController.generated.h"

class URestartWidget;
class UHealthWidget;
class AThirdHUD;

/**
 * 
 */
UCLASS()
class PROJECT2_API AThirdPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<URestartWidget> RestartWidgetClass;

	void ShowRestartWidget();
	void HideRestartWidget();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UHealthWidget> HealthWidgetClass;

	void UpdateHealthPercent(float HealthPercent);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TObjectPtr<URestartWidget> RestartWidget;

	UPROPERTY()
	TObjectPtr<UHealthWidget> HealthWidget;

	UPROPERTY()
	TObjectPtr<AThirdHUD> ThirdHUD;
};
