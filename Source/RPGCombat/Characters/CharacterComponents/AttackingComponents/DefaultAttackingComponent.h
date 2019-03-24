// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterComponents/CharacterAttackingComponent.h"
#include "DefaultAttackingComponent.generated.h"

/**
 * 
 */
UCLASS()
class RPGCOMBAT_API UDefaultAttackingComponent : public UCharacterAttackingComponent
{
	GENERATED_BODY()

	virtual void PrimaryAttack() override;
	virtual void OnAttachedToCharacter(AWeapon* NewWeapon) override;
};
