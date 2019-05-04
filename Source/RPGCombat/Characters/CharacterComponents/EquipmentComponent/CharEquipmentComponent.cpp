// Fill out your copyright notice in the Description page of Project Settings.

#include "CharEquipmentComponent.h"
#include "Engine/World.h"
#include "Weapons/Weapon.h"
#include "GameFramework/Character.h"
#include "Characters/CharacterAnimInterface.h"

// Sets default values for this component's properties
UCharEquipmentComponent::UCharEquipmentComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCharEquipmentComponent::BeginPlay() {
	Super::BeginPlay();

	// ...

}


// Called every frame
void UCharEquipmentComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UCharEquipmentComponent::OnItemEquipped(FItem ItemToEquip) {
	switch (ItemToEquip.ItemType) {
	case (EItemType::WEAPON): {
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

	//Weapon equipment rules.
	if (NewWeapon->WeaponInformations.Usage == EWeaponUsage::ONEHANDED) {
		if (NewWeapon->WeaponInformations.PrefferedHand == EPreferredHand::LEFT) {
			if (LeftHand) {
				LeftHand->OnDetachFromCharacter();
			}
			LeftHand = NewWeapon;
			CheckOfHand(RightHand, EPreferredHand::RIGHT);

		}
		else if (NewWeapon->WeaponInformations.PrefferedHand == EPreferredHand::RIGHT) {
			if (RightHand) {
				RightHand->OnDetachFromCharacter();
			}
			RightHand = NewWeapon;
			CheckOfHand(LeftHand, EPreferredHand::LEFT);

		}
		else {
			if (RightHand == nullptr) {
				RightHand = NewWeapon;
				SocketName = NewWeapon->GetWeaponAttachingSocketName(EPreferredHand::RIGHT);

				CheckOfHand(LeftHand, EPreferredHand::LEFT);

			}
			else if (LeftHand == nullptr) {
				LeftHand = NewWeapon;
				SocketName = NewWeapon->GetWeaponAttachingSocketName(EPreferredHand::LEFT);
				CheckOfHand(RightHand, EPreferredHand::RIGHT);
			}
			else {
				RightHand->OnDetachFromCharacter();
				RightHand = NewWeapon;
				SocketName = NewWeapon->GetWeaponAttachingSocketName(EPreferredHand::RIGHT);
				CheckOfHand(LeftHand, EPreferredHand::LEFT);
			}
		}
	}
	else if (NewWeapon->WeaponInformations.Usage == EWeaponUsage::TWOHANDED) {
		if (LeftHand) {
			LeftHand->OnDetachFromCharacter();
		}
		if (RightHand) {
			RightHand->OnDetachFromCharacter();
		}

		if (NewWeapon->WeaponInformations.PrefferedHand == EPreferredHand::LEFT) {
			LeftHand = NewWeapon;
			RightHand = nullptr;
		}
		else {
			RightHand = NewWeapon;
			LeftHand = nullptr;
		}
	}

	//Attach to character
	NewWeapon->OnAttachedToCharacter();
	FAttachmentTransformRules newAttachmentTransformRules(EAttachmentRule::KeepRelative, true);
	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	NewWeapon->AttachToComponent(OwnerCharacter->GetMesh(), newAttachmentTransformRules, SocketName);



	UAnimInstance* CharacterAnimInstance = OwnerCharacter->GetMesh()->GetAnimInstance();
	if (CharacterAnimInstance && CharacterAnimInstance->GetClass()->ImplementsInterface(UCharacterAnimInterface::StaticClass())) {
		ICharacterAnimInterface::Execute_SetWeaponType(CharacterAnimInstance, NewWeapon->WeaponInformations.Type);
	}
}

void UCharEquipmentComponent::OnArmorEquipped(FItem ArmorToEquip) { }

void UCharEquipmentComponent::CheckOfHand(AWeapon* Hand, EPreferredHand preffer_hand) {
	if (Hand != nullptr) {
		if (Hand->WeaponInformations.Usage == EWeaponUsage::TWOHANDED) {
			Hand->OnDetachFromCharacter();
			if (preffer_hand == EPreferredHand::RIGHT) {
				RightHand = nullptr;
			}
			else {
				LeftHand = nullptr;
			}
		}
	}
}
