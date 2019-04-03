// Fill out your copyright notice in the Description page of Project Settings.

#include "TwoHandedAttackingComponent.h"

void UTwoHandedAttackingComponent::OnAttachedToCharacter(AWeapon* NewWeapon) {
	Super::OnAttachedToCharacter(NewWeapon);
	//TODO DFS
	UE_LOG(LogTemp, Warning, TEXT("UTwoHandedAttackingComponent::OnAttachedToCharacter"));
}

void UTwoHandedAttackingComponent::PrimaryAttack(){
	Super::PrimaryAttack();
	UE_LOG(LogTemp, Warning, TEXT("TwoHandedAttackingComponent->PrimaryAttack"));
}
