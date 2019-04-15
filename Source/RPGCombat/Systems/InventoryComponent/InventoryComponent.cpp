// http://mehmetcengiz.github.io

#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0 ; i < SlotSize; i++) {
		bAreInventorySlotsEmpty.Add(false);
	}

}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UInventoryComponent::AddItem(UItem* Item) {
	if (!ensure(Item != NULL)) return;
	if (IsInventoryFull()) { return; }

	//Add Item
}

void UInventoryComponent::AddItem(UItem* Item, int32 SlotIndex) {
	if (!ensure(Item != NULL))	return;
	if (IsInventoryFull()) 		return;
	if (!SlotIndex<SlotSize)	return;

	//Add item by slot.
	if(bAreInventorySlotsEmpty[SlotIndex]) {
		SetItemAt(Item, SlotIndex);			
	}
	else {
				
	}

}

void UInventoryComponent::SetItemAt(UItem* Item, int32 SlotIndex) {
	if (!ensure(Item != NULL))	return;

	for (auto item : InventoryItems) {
		if(item->SlotIndex == SlotIndex) {
			return;
		}
	}

}

void UInventoryComponent::DeleteItem(int32 SlotIndex) {
	
}

bool UInventoryComponent::IsInventoryFull() {
	return ItemCount >= SlotSize;
}

