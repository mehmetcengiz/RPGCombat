// Fill out your copyright notice in the Description page of Project Settings.

#include "CharEquipmentComponent.h"
#include "Engine/World.h"
#include "Weapons/Weapon.h"
#include "GameFramework/Character.h"

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

	FName SocketName = NewWeapon->GetWeaponAttachingSocketName();

	if(NewWeapon->WeaponInformations.Usage == EWeaponUsage::ONEHANDED) {
		if(NewWeapon->WeaponInformations.PrefferedHand == EPreferredHand::LEFT) {
			if(LeftHand) {
				LeftHand->OnDetachFromCharacter();
			}
			LeftHand = NewWeapon;
		}else if(NewWeapon->WeaponInformations.PrefferedHand == EPreferredHand::RIGHT) {
			if(RightHand) {
				RightHand->OnDetachFromCharacter();
			}
			RightHand = NewWeapon;
		}else {
			if(RightHand == NULL) {
				RightHand = NewWeapon;
				SocketName = NewWeapon->GetWeaponAttachingSocketName(EPreferredHand::RIGHT);
			}else if(LeftHand == NULL) {
				LeftHand = NewWeapon;
				SocketName = NewWeapon->GetWeaponAttachingSocketName(EPreferredHand::LEFT);
			}else {
				RightHand->OnDetachFromCharacter();
				RightHand = NewWeapon;
				SocketName = NewWeapon->GetWeaponAttachingSocketName(EPreferredHand::RIGHT);
			}
		}
	}else if(NewWeapon->WeaponInformations.Usage == EWeaponUsage::TWOHANDED) {
		//When equipped weapon is Two Handed weapon.
		if(LeftHand) {
			LeftHand->OnDetachFromCharacter();
		}
		if(RightHand) {
			RightHand->OnDetachFromCharacter();
		}

		if(NewWeapon->WeaponInformations.PrefferedHand == EPreferredHand::LEFT) {
			LeftHand = NewWeapon;
		}else{
			RightHand = NewWeapon;
		}
	}

	NewWeapon->OnAttachedToCharacter();

	FAttachmentTransformRules newAttachmentTransformRules(EAttachmentRule::KeepRelative, true);
	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	NewWeapon->AttachToComponent(OwnerCharacter->GetMesh(), newAttachmentTransformRules, SocketName);

}

void UCharEquipmentComponent::OnArmorEquipped(FItem ArmorToEquip) {
	
}

