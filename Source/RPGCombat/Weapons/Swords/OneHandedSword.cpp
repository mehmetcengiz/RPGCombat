// Fill out your copyright notice in the Description page of Project Settings.

#include "OneHandedSword.h"
#include "Characters/RPGCombatCharacter.h"
#include "Characters/CharacterComponents/AttackingComponents/SwordAndShieldAttackingComponent.h"

AOneHandedSword::AOneHandedSword(){
	WeaponType = EWeaponType::SWORDANDSHIELD;
}

TSubclassOf<UCharacterAttackingComponent> AOneHandedSword::GetAttackingComponent(ARPGCombatCharacter* ParentCharacter) {
	if(ParentCharacter) {	
		UE_LOG(LogTemp, Warning, TEXT("GetAttacking component parent cast not faild. I am in shocked!"));
		//return USwordAndShieldAttackingComponent::StaticClass();
	}
	
	//if character has Shield return shield attackingcomponent
	//else
	return AttackingComponent;
}
