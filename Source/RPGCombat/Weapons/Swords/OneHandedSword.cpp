// Fill out your copyright notice in the Description page of Project Settings.

#include "OneHandedSword.h"
#include "Characters/RPGCombatCharacter.h"
#include "Characters/CharacterComponents/AttackingComponents/SwordAndShieldAttackingComponent.h"
#include "Characters/CharacterComponents/AttackingComponents/DoubleOneHandedAttackingComp.h"

AOneHandedSword::AOneHandedSword(){
	WeaponType = EWeaponType::SWORD;
}

TSubclassOf<UCharacterAttackingComponent> AOneHandedSword::GetAttackingComponent(ARPGCombatCharacter* ParentCharacter) {
	if(ParentCharacter) {	
		UE_LOG(LogTemp, Warning, TEXT("GetAttacking component parent cast not faild. I am in shocked!"));
		if(ParentCharacter->CurrentWeapon_L) {
			if(ParentCharacter->CurrentWeapon_L->WeaponType == EWeaponType::SHIELD) {
				return USwordAndShieldAttackingComponent::StaticClass();
			}
		
			if(	ParentCharacter->CurrentWeapon_L->WeaponType == EWeaponType::SWORD) {
				return UDoubleOneHandedAttackingComp::StaticClass();
			}
			
		}

		if(ParentCharacter->CurrentWeapon_R) {
			if(ParentCharacter->CurrentWeapon_R->WeaponType == EWeaponType::SWORD) {
				return UDoubleOneHandedAttackingComp::StaticClass();
			}
		}

	}
	return AttackingComponent;
}
