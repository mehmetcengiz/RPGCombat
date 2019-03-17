// Fill out your copyright notice in the Description page of Project Settings.

#include "OneHandedAttackingComponent.h"

void UOneHandedAttackingComponent::OnAttachedToCharacter(AWeapon* NewWeapon) {
	Super::OnAttachedToCharacter(NewWeapon);
	//TODO DFS
	UE_LOG(LogTemp, Warning, TEXT("UOneHandedAttackingComponent::OnAttachedToCharacter"));
}
