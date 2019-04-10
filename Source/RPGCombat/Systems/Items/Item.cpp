// http://mehmetcengiz.github.io

#include "Item.h"

/*Local includes*/
#include "Characters/RPGCombatCharacter.h"



void UItem::UseItem(ARPGCombatCharacter* UsedCharacter) {
	FString Name = UsedCharacter->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Used item"), *Name);

}
