// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterComponents/CharacterAttackingComponent.h"
#include "BowAttackingComponent.generated.h"

/**
 * 
 */
UCLASS()
class RPGCOMBAT_API UBowAttackingComponent : public UCharacterAttackingComponent
{
	GENERATED_BODY()


protected:

	virtual void PrimaryAttack() override;
	virtual void OnAttachedToCharacter() override;
};
