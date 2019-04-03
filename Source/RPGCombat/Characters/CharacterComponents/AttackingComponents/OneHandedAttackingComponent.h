// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterComponents/CharacterAttackingComponent.h"
#include "OneHandedAttackingComponent.generated.h"

/**
 * 
 */
UCLASS()
class RPGCOMBAT_API UOneHandedAttackingComponent : public UCharacterAttackingComponent
{
	GENERATED_BODY()
public:
	virtual void OnAttachedToCharacter(AWeapon* NewWeapon) override;
	virtual void PrimaryAttack() override;
};
