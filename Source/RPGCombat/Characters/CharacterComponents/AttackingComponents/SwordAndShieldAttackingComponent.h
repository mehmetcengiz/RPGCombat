// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterComponents/CharacterAttackingComponent.h"
#include "SwordAndShieldAttackingComponent.generated.h"

/**
 * 
 */
UCLASS()
class RPGCOMBAT_API USwordAndShieldAttackingComponent : public UCharacterAttackingComponent
{
	GENERATED_BODY()

protected:
	virtual void PrimaryAttack() override;
	virtual void OnAttachedToCharacter(AWeapon* NewWeapon) override;
};
