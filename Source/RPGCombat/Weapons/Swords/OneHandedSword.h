// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Weapon.h"
#include "OneHandedSword.generated.h"

/**
 * 
 */
UCLASS()
class RPGCOMBAT_API AOneHandedSword : public AWeapon
{
	GENERATED_BODY()

public:
	AOneHandedSword();

	virtual TSubclassOf<class UCharacterAttackingComponent> GetAttackingComponent(ARPGCombatCharacter* ParentCharacter) override;
	virtual FName GetWeaponAttachingSocketName(EPreferredHand PrefferedHand) override;

	UPROPERTY(EditDefaultsOnly, Category = "OneHanded Weapon")
	FName WeaponLeftSocket;
	UPROPERTY(EditDefaultsOnly, Category = "OneHanded Weapon")
	FName WeaponRightSocket;
};
