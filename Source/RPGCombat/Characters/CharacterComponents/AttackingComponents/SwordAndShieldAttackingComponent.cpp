// Fill out your copyright notice in the Description page of Project Settings.

#include "SwordAndShieldAttackingComponent.h"

void USwordAndShieldAttackingComponent::PrimaryAttack() {
	Super::PrimaryAttack();
	UE_LOG(LogTemp, Warning, TEXT("USwordAndShieldAttackingComponent::PrimaryAttack"));
}
void USwordAndShieldAttackingComponent::OnAttachedToCharacter(AWeapon* NewWeapon) {
	Super::OnAttachedToCharacter(NewWeapon);
	//TODO DFS
	UE_LOG(LogTemp, Warning, TEXT("USwordAndShieldAttackingComponent::OnAttachedToCharacter"));
}
