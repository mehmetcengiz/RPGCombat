// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterComponents/CharacterAttackingComponent.h"
#include "TwoHandedAttackingComponent.generated.h"

/**
 * 
 */
UCLASS()
class RPGCOMBAT_API UTwoHandedAttackingComponent : public UCharacterAttackingComponent
{
	GENERATED_BODY()
	
	virtual void OnAttachedToCharacter(AWeapon* NewWeapon) override;
};
