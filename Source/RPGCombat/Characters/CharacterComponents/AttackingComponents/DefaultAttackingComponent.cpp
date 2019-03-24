// Fill out your copyright notice in the Description page of Project Settings.

#include "DefaultAttackingComponent.h"


void UDefaultAttackingComponent::PrimaryAttack() {
	Super::PrimaryAttack();
	//TODO DFS
	UE_LOG(LogTemp, Warning, TEXT("DefaultAttackingComponent::PrimaryAttack()"));
}

void UDefaultAttackingComponent::OnAttachedToCharacter(AWeapon* NewWeapon) {
	Super::OnAttachedToCharacter(NewWeapon);
	//TODO DFS
	UE_LOG(LogTemp, Warning, TEXT("DefaultAttackingComponent::OnAttachedToCharacter()"));
}