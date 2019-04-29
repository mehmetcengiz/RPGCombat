// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Systems/Items/Item.h"
#include "CharEquipmentComponent.generated.h"

class AWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPGCOMBAT_API UCharEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharEquipmentComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	/*Weapons*/
	UPROPERTY(EditInstanceOnly,BlueprintReadWrite, Category = "Equipment")
	AWeapon* LeftHand = nullptr;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Equipment")
	AWeapon* RightHand = nullptr;

	/*Body equipments*/
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Equipment")
	AActor* Helmet = nullptr;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Equipment")
	AActor* Necklace = nullptr;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Equipment")
	AActor* Body = nullptr;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Equipment")
	AActor* Belt = nullptr;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Equipment")
	AActor* Pants = nullptr;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Equipment")
	AActor* Boots = nullptr;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Equipment")
	AActor* Shoulder = nullptr;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Equipment")
	AActor* Arm	= nullptr;

  	void OnItemEquipped(FItem ItemToEquip);
	void UpdateStatsOfOwnerCharacter();
	void DropItem(FItem ItemToDrop);

	void OnWeaponEquipped(FItem WeaponToEquip);
	void OnArmorEquipped(FItem ArmorToEquip);

	void CheckOfHand(AWeapon* Hand);
	

};
