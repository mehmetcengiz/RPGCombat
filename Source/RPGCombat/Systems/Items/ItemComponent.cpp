// http://mehmetcengiz.github.io

#include "ItemComponent.h"

// Sets default values for this component's properties
UItemComponent::UItemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UItemComponent::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < SlotSize; i++) {
		UItem* EmptySlot = NewObject<UItem>();
		EmptySlot->ItemName = FText::AsNumber(i);
		InventoryItems.Add(EmptySlot);
	}
	
}


// Called every frame
void UItemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

