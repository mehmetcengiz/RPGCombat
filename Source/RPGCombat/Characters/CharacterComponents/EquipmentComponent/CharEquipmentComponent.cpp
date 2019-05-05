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

void UCharEquipmentComponent::OnItemEquipped(FItem itemToEquip) {
	switch (itemToEquip.ItemType) {
	case (EItemType::WEAPON): {
		OnWeaponEquipped(itemToEquip);
		break;
	}
	case (EItemType::ARMOR): {
		OnArmorEquipped(itemToEquip);
		break;
	}
	default:
		break;
	}
}


void UCharEquipmentComponent::OnWeaponEquipped(FItem weaponToEquip) {
	AWeapon* newWeapon = SpawnWeaponByClass(weaponToEquip.ActorClass);
	if (!ensure(newWeapon != NULL)) return;
	FName SocketName = newWeapon->GetWeaponAttachingSocketName();

	if (newWeapon->WeaponInformations.Usage == EWeaponUsage::ONEHANDED) {
		OnNewWeaponOneHanded(newWeapon, OUT SocketName);
	}
	else if (newWeapon->WeaponInformations.Usage == EWeaponUsage::TWOHANDED) {
		OnNewWeaponTwoHanded(newWeapon);
	}

	bIsEquippedWeapon = (LeftHand != nullptr) || (RightHand != nullptr);

	ACharacter* ownerCharacter = Cast<ACharacter>(GetOwner());
	if (!ensure(ownerCharacter != NULL)) return;
	AttachWeaponToCharacter(newWeapon, SocketName, ownerCharacter);
	UpdateAnimationInterface(newWeapon, ownerCharacter);


	//AttackingComponentClass = newWeapon->GetAttackingComponent();
}

void UCharEquipmentComponent::OnNewWeaponTwoHanded(AWeapon* newWeapon) {
	if (LeftHand) { LeftHand->OnDetachFromCharacter(); }
	if (RightHand) { RightHand->OnDetachFromCharacter(); }

	if (newWeapon->WeaponInformations.PrefferedHand == EPreferredHand::LEFT) {
		LeftHand = newWeapon;
		RightHand = nullptr;
	}
	else {
		RightHand = newWeapon;
		LeftHand = nullptr;
	}
}

void UCharEquipmentComponent::OnNewWeaponOneHanded(AWeapon* newWeapon, FName& SocketName) {
	if (newWeapon->WeaponInformations.PrefferedHand == EPreferredHand::LEFT) {
		if (LeftHand) {
			LeftHand->OnDetachFromCharacter();
		}
		LeftHand = newWeapon;
		CheckOfHand(&RightHand);

	}
	else if (newWeapon->WeaponInformations.PrefferedHand == EPreferredHand::RIGHT) {
		if (RightHand) {
			RightHand->OnDetachFromCharacter();
		}
		RightHand = newWeapon;
		CheckOfHand(&LeftHand);

	}
	else {
		if (RightHand == nullptr) {
			RightHand = newWeapon;
			SocketName = newWeapon->GetWeaponAttachingSocketName(EPreferredHand::RIGHT);

			CheckOfHand(&LeftHand);

		}
		else if (LeftHand == nullptr) {
			LeftHand = newWeapon;
			SocketName = newWeapon->GetWeaponAttachingSocketName(EPreferredHand::LEFT);
			CheckOfHand(&RightHand);
		}
		else {
			RightHand->OnDetachFromCharacter();
			RightHand = newWeapon;
			SocketName = newWeapon->GetWeaponAttachingSocketName(EPreferredHand::RIGHT);
			CheckOfHand(&LeftHand);
		}
	}
}

void UCharEquipmentComponent::AttachWeaponToCharacter(AWeapon* newWeapon, FName socketName, ACharacter* ownerCharacter) {
	//Attach to character
	newWeapon->OnAttachedToCharacter();
	FAttachmentTransformRules newAttachmentTransformRules(EAttachmentRule::KeepRelative, true);
	newWeapon->AttachToComponent(ownerCharacter->GetMesh(), newAttachmentTransformRules, socketName);
}

void UCharEquipmentComponent::UpdateAnimationInterface(AWeapon* newWeapon, ACharacter* ownerCharacter) {
	UAnimInstance* CharacterAnimInstance = ownerCharacter->GetMesh()->GetAnimInstance();
	if (CharacterAnimInstance && CharacterAnimInstance->GetClass()->ImplementsInterface(
		UCharacterAnimInterface::StaticClass())) {
		ICharacterAnimInterface::Execute_SetWeaponType(CharacterAnimInstance, newWeapon->WeaponInformations.Type);
		ICharacterAnimInterface::Execute_SetIsEquippedWeapon(CharacterAnimInstance, bIsEquippedWeapon);
	}
}

void UCharEquipmentComponent::OnArmorEquipped(FItem armorToEquip) { }

void UCharEquipmentComponent::CheckOfHand(AWeapon** hand) {
	if (*(hand) != nullptr) {
		if ((*hand)->WeaponInformations.Usage == EWeaponUsage::TWOHANDED) {
			(*hand)->OnDetachFromCharacter();
			(*hand) = nullptr;
		}
	}
}

AWeapon* UCharEquipmentComponent::SpawnWeaponByClass(UClass* weaponClass) const {
	//Spawn weapon by class.
	const FVector location(0.0f, 0.0f, 0.0f);
	const FRotator rotation(0.0f, 0.0f, 0.0f);
	const FActorSpawnParameters spawnInfo;
	const auto newWeapon = GetWorld()->SpawnActor<AWeapon>(weaponClass, location, rotation, spawnInfo);

	return newWeapon;
}
