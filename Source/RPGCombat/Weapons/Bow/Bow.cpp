// Fill out your copyright notice in the Description page of Project Settings.

#include "Bow.h"


ABow::ABow() {
	PrimaryActorTick.bCanEverTick = true;
	
}

void ABow::BeginPlay() {
	Super::BeginPlay();
	WeaponType = EWeaponType::BOW;
}


void ABow::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void ABow::OnPrimaryAttack() {
	Super::OnPrimaryAttack();
	UE_LOG(LogTemp, Warning, TEXT("Weapon>>Bow>>OnPrimaryAttack"));
}