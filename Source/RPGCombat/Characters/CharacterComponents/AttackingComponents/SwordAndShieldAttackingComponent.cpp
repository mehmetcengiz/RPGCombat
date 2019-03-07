// Fill out your copyright notice in the Description page of Project Settings.

#include "SwordAndShieldAttackingComponent.h"

void USwordAndShieldAttackingComponent::PrimaryAttack() {
	Super::PrimaryAttack();
}
void USwordAndShieldAttackingComponent::OnAttachedToCharacter(AWeapon* NewWeapon) {
	Super::OnAttachedToCharacter(Weapon);
}
