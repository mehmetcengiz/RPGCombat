// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterAttackingComponent.h"
#include "GameFramework/Character.h"
#include "Weapons/Weapon.h"

// Sets default values for this component's properties
UCharacterAttackingComponent::UCharacterAttackingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCharacterAttackingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCharacterAttackingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCharacterAttackingComponent::PrimaryAttack(){
	UE_LOG(LogTemp, Warning, TEXT("CharacterAttackingComponent>>Primary Attack"));
}

void UCharacterAttackingComponent::OnAttachedToCharacter(AWeapon* NewWeapon) {
	UE_LOG(LogTemp, Warning, TEXT("UCharacterAttackingComponent::OnAttachedToCharacter()"));

	Weapon = NewWeapon;

	FAttachmentTransformRules newAttachmentTransformRules(EAttachmentRule::KeepRelative, true);
	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	Weapon->AttachToComponent(OwnerCharacter->GetMesh(), newAttachmentTransformRules, Weapon->GetWeaponAttachingSocketName());
	Weapon->OnAttachedToCharacter();

}

