// Fill out your copyright notice in the Description page of Project Settings.


#include "PhaseTransitionWorldSubsystem.h"

EPhase UPhaseTransitionWorldSubsystem::GetCurrentPhase()
{
	return CurrentPhase;
}

void UPhaseTransitionWorldSubsystem::ChangePhase(const EPhase NextPhase)
{
	CurrentPhase = NextPhase;
	PhaseChanged.Broadcast(CurrentPhase);
	NotifyPlayerOnPhaseChange.Broadcast();
}
