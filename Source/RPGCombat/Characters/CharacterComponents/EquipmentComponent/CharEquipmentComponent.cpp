// Fill out your copyright notice in the Description page of Project Settings.

#include "CharEquipmentComponent.h"
#include "Engine/World.h"
#include "Weapons/Weapon.h"

// Sets default values for this component's properties
UCharEquipmentComponent::UCharEquipmentComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCharEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCharEquipmentComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCharEquipmentComponent::OnItemEquipped(FItem ItemToEquip) {
	switch (ItemToEquip.ItemType) {
		case (EItemType::WEAPON):{
			OnWeaponEquipped(ItemToEquip);
			break;
		}
		case (EItemType::ARMOR): {
			OnArmorEquipped(ItemToEquip);
			break;
		}
		default:
			break;
	}
}

void UCharEquipmentComponent::OnWeaponEquipped(FItem WeaponToEquip) {
	
	//Spawn weapon by class.
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	AWeapon* NewWeapon = GetWorld()->SpawnActor<AWeapon>(WeaponToEquip.ActorClass, Location, Rotation, SpawnInfo);

	//NUll check.
	if (!ensure(NewWeapon != NULL)) return;

	if(NewWeapon->WeaponUsage == EWeaponUsage::ONEHANDED) {
		if(NewWeapon->PrefferedHand == EPreferredHand::LEFT) {
			if(LeftHand) {
				LeftHand->OnDetachFromCharacter();
			}
			LeftHand = NewWeapon;
		}else if(NewWeapon->PrefferedHand == EPreferredHand::RIGHT) {
			if(RightHand) {
				RightHand->OnDetachFromCharacter();
			}
			RightHand = NewWeapon;
		}else {
			if(RightHand == NULL) {
				RightHand = NewWeapon;
				RightHand->OnAttachedToCharacter();
			}else if(LeftHand == NULL) {
				LeftHand = NewWeapon;
				LeftHand->OnAttachedToCharacter();
			}else {
				
			}



		}


	}else if(NewWeapon->WeaponUsage == EWeaponUsage::TWOHANDED) {
		//When equipped weapon is Two Handed weapon.
		if(LeftHand) {
			LeftHand->OnDetachFromCharacter();
		}
		if(RightHand) {
			RightHand->OnDetachFromCharacter();
		}

		if(NewWeapon->PrefferedHand == EPreferredHand::LEFT) {
			LeftHand = NewWeapon;
			LeftHand->OnAttachedToCharacter();
		}else{
			RightHand = NewWeapon;
			RightHand->OnAttachedToCharacter();
		}


	}


}

void UCharEquipmentComponent::OnArmorEquipped(FItem ArmorToEquip) {
	
}

