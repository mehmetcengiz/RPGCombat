// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Systems/Items/Item.h"
#include "CharEquipmentComponent.generated.h"

enum class EPreferredHand : unsigned char;
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

	UPROPERTY(BlueprintReadWrite, Category = "Equipment")
	bool bIsEquippedWeapon = false;

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

	UFUNCTION(BlueprintCallable,Category = "Equipment")
  	void OnItemEquipped(FItem itemToEquip);
	//void UpdateStatsOfOwnerCharacter();
	//void DropItem(FItem item_to_drop);

	void OnWeaponEquipped(FItem weaponToEquip);
	void OnArmorEquipped(FItem armorToEquip);

	static void CheckOfHand(AWeapon** hand);
	

private:
	AWeapon* SpawnWeaponByClass(UClass* weaponClass) const;
	void OnNewWeaponTwoHanded(AWeapon* newWeapon);
	void OnNewWeaponOneHanded(AWeapon* newWeapon, FName& SocketName);
	static void AttachWeaponToCharacter(AWeapon* newWeapon, FName socketName, class ACharacter* ownerCharacter);
	void UpdateAnimationInterface(AWeapon* newWeapon, class ACharacter* ownerCharacter);
};
