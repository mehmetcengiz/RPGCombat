// http://mehmetcengiz.github.io

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Items/Item.h"
#include "ItemComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPGCOMBAT_API UItemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UItemComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	UItem* ItemInfo;
};
