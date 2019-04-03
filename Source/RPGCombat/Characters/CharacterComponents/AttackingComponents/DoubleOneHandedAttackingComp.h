// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterComponents/CharacterAttackingComponent.h"
#include "DoubleOneHandedAttackingComp.generated.h"

/**
 * 
 */
UCLASS()
class RPGCOMBAT_API UDoubleOneHandedAttackingComp : public UCharacterAttackingComponent
{
	GENERATED_BODY()
		
public:
	virtual void OnAttachedToCharacter(AWeapon* NewWeapon) override;
	virtual void PrimaryAttack() override;
};
