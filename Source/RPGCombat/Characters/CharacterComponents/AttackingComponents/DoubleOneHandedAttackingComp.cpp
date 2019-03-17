// Fill out your copyright notice in the Description page of Project Settings.

#include "DoubleOneHandedAttackingComp.h"

void UDoubleOneHandedAttackingComp::OnAttachedToCharacter(AWeapon* NewWeapon) {
	Super::OnAttachedToCharacter(NewWeapon);
	//TODO DFS
	UE_LOG(LogTemp, Warning, TEXT("UDoubleOneHandedAttackingComp::OnAttachedToCharacter"));
}
