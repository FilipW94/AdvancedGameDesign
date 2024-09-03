// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "PhaseTransitionWorldSubsystem.generated.h"

/**
 * 
 */
UENUM(Blueprintable)
enum EPhase : uint8
{
	PhaseOne UMETA(DisplayName = "PhaseOne"),
	PhaseTwo UMETA(DisplayName = "PhaseTwo"),
	PhaseThree UMETA(DisplayName = "PhaseThree"),
	PhaseFour UMETA(DisplayName = "PhaseFour")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPhaseChanged, EPhase, NextPhase);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNotifyPlayerOnPhaseChange);

UCLASS()
class AGDTESTING_API UPhaseTransitionWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	EPhase CurrentPhase;

	UFUNCTION(BlueprintCallable, Category="Phase Subsystem")
	EPhase GetCurrentPhase();

	UFUNCTION(BlueprintCallable, Category="Phase Subsystem")
	void ChangePhase(const EPhase NextPhase);

	UPROPERTY(BlueprintAssignable)
	FPhaseChanged PhaseChanged;

	UPROPERTY(BlueprintAssignable)
	FNotifyPlayerOnPhaseChange NotifyPlayerOnPhaseChange;
	
};
