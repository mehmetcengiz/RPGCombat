// Fill out your copyright notice in the Description page of Project Settings.

#include "OneHandedSword.h"
#include "Characters/CharacterComponents/EquipmentComponent/CharEquipmentComponent.h"
#include "Characters/CharacterComponents/AttackingComponents/SwordAndShieldAttackingComponent.h"
#include "Characters/CharacterComponents/AttackingComponents/DoubleOneHandedAttackingComp.h"

AOneHandedSword::AOneHandedSword(){
}

TSubclassOf<UCharacterAttackingComponent> AOneHandedSword::GetAttackingComponent(UCharEquipmentComponent* equipmentComponent) {
	if(equipmentComponent) {	
		UE_LOG(LogTemp, Warning, TEXT("GetAttacking component parent cast not faild. I am in shocked!"));
		if(equipmentComponent->LeftHand) {
			if(equipmentComponent->LeftHand->WeaponInformations.Type == EWeaponType::SWORDANDSHIELD) {
				return USwordAndShieldAttackingComponent::StaticClass();
			}
		
			if(equipmentComponent->LeftHand->WeaponInformations.Type == EWeaponType::ONEHANDED) {
				return UDoubleOneHandedAttackingComp::StaticClass();
			}
			
		}

		if(equipmentComponent->RightHand) {
			if(equipmentComponent->RightHand->WeaponInformations.Type == EWeaponType::ONEHANDED) {
				return UDoubleOneHandedAttackingComp::StaticClass();
			}
		}

	}
	return WeaponInformations.AttackingComponentClass;
}

FName AOneHandedSword::GetWeaponAttachingSocketName(EPreferredHand preferredHand) {	
	return preferredHand == EPreferredHand::LEFT ? WeaponInformations.LeftHandSocketName : WeaponInformations.RightHandSocketName;
}
