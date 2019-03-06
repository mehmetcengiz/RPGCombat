// Fill out your copyright notice in the Description page of Project Settings.

#include "BowAttackingComponent.h"

void UBowAttackingComponent::PrimaryAttack() {
	Super::PrimaryAttack();
	UE_LOG(LogTemp, Warning, TEXT("UBowAttackingComponent::PrimaryAttack()"));
}

void UBowAttackingComponent::OnAttachedToCharacter(class AWeapon* NewWeapon) {
	Super::OnAttachedToCharacter(NewWeapon);
	UE_LOG(LogTemp, Warning, TEXT("UBowAttackingComponent::OnAttachedToCharacter()"));
}
