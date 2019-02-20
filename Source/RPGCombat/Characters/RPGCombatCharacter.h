// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "CharacterAnimInterface.h"

#include "RPGCombatCharacter.generated.h"

class AWeapon;

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

	UFUNCTION(BlueprintCallable,Category="Weapon")
	void EquipWeapon(AWeapon* Weapon);

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);



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
	void AddControllerYawInput(float val) override;
	void LookUpAtRate(float Rate);
	void AddControllerPitchInput(float val) override;
	void MoveForward(float Value);
	void MoveRight(float Value);


	UPROPERTY(BlueprintReadWrite, Category = "Weapon")
	AWeapon* Weapon;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon")
	bool bIsEquippedWeapon;

	//Attacking.
	void PrimaryAttackPressed();

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	AActor* ActorToFocus;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Debug")
	AActor* FocusActorToDebug;

	void TurnFocusedActor();
	void SelectFocusedActor();
	
	UPROPERTY(BlueprintReadWrite, Category = "Character")
	bool bIsFocused;

protected:
	UFUNCTION(BlueprintCallable,Category ="Character Movements")
	void SetFocusActor(AActor* NewActorToFocus) { ActorToFocus = NewActorToFocus; }
	
private:
	ICharacterAnimInterface* CharacterAnimInterface;
	UAnimInstance* CharacterAnimInstance;
	bool bIsImplementsCharacterAnimInterface;



};
