// Fill out your copyright notice in the Description page of Project Settings.

#include "BowAttackingComponent.h"

void UBowAttackingComponent::PrimaryAttack() {
	Super::PrimaryAttack();
	//TODO DFS
	UE_LOG(LogTemp, Warning, TEXT("UBowAttackingComponent::PrimaryAttack()"));
}

void UBowAttackingComponent::OnAttachedToCharacter(AWeapon* NewWeapon) {
	Super::OnAttachedToCharacter(NewWeapon);
	//TODO DFS
	UE_LOG(LogTemp, Warning, TEXT("UBowAttackingComponent::OnAttachedToCharacter()"));
}
