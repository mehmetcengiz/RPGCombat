// http://mehmetcengiz.github.io

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Items/Item.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPGCOMBAT_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();
	// Called every frame
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	TArray<UItem*> GetInventoryItems() { return InventoryItems; }

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int32 GetInventorySize() { return InventorySize; }

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void PickUpItem(AActor* ActorToPickUP);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItemToInventory(UItem* Item);

protected:
	// Called when the game starts
	void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	TArray<UItem*> InventoryItems;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	TArray<bool> InventorySlotInfo;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 InventorySize = 20;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Inventory")
	int32 MaxItemCountPerSlot = 9999;

public:

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SwapItemSlots(UItem* DraggedItem, UItem* DroppedTo);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetItemSlot(UItem* Item, int32 NewSlot);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SplitItem(UItem* ItemToSplit, int32 SplitQuantity, int32 NewSlot);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void CombineItems(UItem* ItemA, UItem* ItemB);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void DropItemFromInventory(UItem* Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SplitAndDropItem(UItem* ItemToSplit, int32 SplitQuantity);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SpawnItem(UItem* Item) const;



private:
	void CreateSlotInfo();
	void DisableSlotByInventoryItems();

	UFUNCTION()
	void DeleteFromInventoryItems(UItem* ItemToDelete);

};
