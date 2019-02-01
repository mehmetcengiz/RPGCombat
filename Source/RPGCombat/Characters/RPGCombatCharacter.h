// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RPGCombatCharacter.generated.h"


UENUM(BlueprintType)
enum class EAttackingType : uint8 {
	PRIMARY				UMETA(DisplayName = "Primary Attack"),
	SECONDARY			UMETA(DisplayName = "Secondary Attack"),
	SKILL_A				UMETA(DisplayName = "Skill A"),
	SKILL_B				UMETA(DisplayName = "Skill B")
};

UCLASS()
class RPGCOMBAT_API ARPGCombatCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	// Sets default values for this character's properties
	ARPGCombatCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*Controls and Mechanics*/

	bool bIsCharacterFocused = false;

	/** Base turn rate, in deg/sec.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		float BaseLookUpRate;

	/*Movement Functions*/
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);
	void MoveForward(float Value);
	void MoveRight(float Value);


	UPROPERTY(BlueprintReadWrite, Category = "Weapon")
		class AWeapon* Weapon;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon")
		EAttackingType AttackingType = EAttackingType::PRIMARY;

	//Attacking.
	void PrimaryAttackPressed();
	void PrimaryAttackReleased();

	UPROPERTY(BlueprintReadWrite, Category = "Animation")
	bool bIsAttacking;

	UPROPERTY(BlueprintReadWrite, Category = "Animation")
	float MovingRight;
	UPROPERTY(BlueprintReadWrite, Category = "Animation")
	float MovingForward;

};
