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

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 SlotSize = 10;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	TArray<UItem*> InventoryItems;		
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TArray<UItem*> CurrentItems;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	TArray<UItem*> GetInventoryItems() const { return InventoryItems; }

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void DeleteItem(int32 SlotIndex);

};
