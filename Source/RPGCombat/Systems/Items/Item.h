// http://mehmetcengiz.github.io

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

class ARPGCombatCharacter;

/**
 * 
 */
UCLASS()
class RPGCOMBAT_API UItem : public UObject
{
	GENERATED_BODY()


public:
	virtual void UseItem(ARPGCombatCharacter* UsedCharacter);
};
