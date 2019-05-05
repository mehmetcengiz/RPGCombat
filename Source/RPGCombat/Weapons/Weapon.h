// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8 {
	SWORDANDSHIELD		UMETA(DisplayName = "Sword and Shield"),
	BOW					UMETA(DisplayName = "Bow"),
	MAGE				UMETA(DisplayName = "Mage"),
	ONEHANDED			UMETA(DisplayName = "OneHanded"),
	TWOHANDED			UMETA(DisplayName = "TwoHanded"),
	DOUBLEONEHANDED		UMETA(DisplayName = "Double-OneHanded")
};

UENUM(BlueprintType)
enum class EPreferredHand : uint8 {
	LEFT		UMETA(DisplayName = "Left"),
	RIGHT		UMETA(DisplayName = "Right"),
	BOTH		UMETA(DisplayName = "Both")
};

UENUM(BlueprintType)
enum class EWeaponUsage : uint8 {
	ONEHANDED		UMETA(DisplayName = "OneHanded"),
	TWOHANDED		UMETA(DisplayName = "TwoHanded"),
};

USTRUCT(BlueprintType)
struct FWeaponInfo {
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Informations")
	TSubclassOf<class UCharacterAttackingComponent> AttackingComponentClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Informations")
	EWeaponType Type;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Informations")
	EWeaponUsage Usage;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Informations")
	EPreferredHand PrefferedHand;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Informations")
	FName LeftHandSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Informations")
	FName RightHandSocketName;

};

class ARPGCombatCharacter;
class UCharEquipmentComponent;

UCLASS()
class RPGCOMBAT_API AWeapon : public AActor
{
	GENERATED_BODY()



public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnPrimaryAttack();

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Weapon")
	class UStaticMeshComponent* WeaponMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
	class USphereComponent* WeaponCollision;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	FName WeaponAttachingSocketName;	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual FName GetWeaponAttachingSocketName() const { return WeaponAttachingSocketName; }
	virtual FName GetWeaponAttachingSocketName(EPreferredHand PrefferedHand);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Informations")
	FWeaponInfo WeaponInformations;


	virtual void OnAttachedToCharacter();
	virtual void OnDetachFromCharacter();

	virtual TSubclassOf<class UCharacterAttackingComponent> GetAttackingComponent(UCharEquipmentComponent* equipmentComponent);

};
