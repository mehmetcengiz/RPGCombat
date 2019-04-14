// http://mehmetcengiz.github.io

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/Texture2D.h"
#include "Components/Image.h"
#include "Item.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8 {
	NONE	UMETA(DisplayName = "None"),
	ARMOR	UMETA(DisplayName = "Armor"),
	WEAPON	UMETA(DisplayName = "Weapon"),
	BUILDING_METERIAL	UMETA(DisplayName = "Building Meterial")
};

class ARPGCombatCharacter;

/**
 * 
 */
UCLASS()
class RPGCOMBAT_API UItem : public UObject
{
	GENERATED_BODY()


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	FText ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	TEnumAsByte<EItemType>ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	UTexture2D* Image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	int32 Quantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	bool bCombinable;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	int32 SlotIndex;


	virtual void UseItem(ARPGCombatCharacter* UsedCharacter);
};
