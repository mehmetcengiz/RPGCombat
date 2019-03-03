// Fill out your copyright notice in the Description page of Project Settings.

#include "BowAttackingComponent.h"

void UBowAttackingComponent::PrimaryAttack() {
	Super::PrimaryAttack();
	UE_LOG(LogTemp, Warning, TEXT("UBowAttackingComponent::PrimaryAttack()"));
}

void UBowAttackingComponent::OnAttachedToCharacter() {
	Super::OnAttachedToCharacter();
	UE_LOG(LogTemp, Warning, TEXT("UBowAttackingComponent::OnAttachedToCharacter()"));
}
