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
	
	for (int32 i = 0; i < SlotSize; i++) {
		UItem* EmptySlot = NewObject<UItem>();
		EmptySlot->ItemName = FText::AsNumber(i);
		InventoryItems.Add(EmptySlot);
	}

	for (auto current_item : CurrentItems) {
		
		//Add items.
	}


}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UInventoryComponent::AddItem(UItem* Item) {
	
}

void UInventoryComponent::DeleteItem(int32 SlotIndex) {
	
}

