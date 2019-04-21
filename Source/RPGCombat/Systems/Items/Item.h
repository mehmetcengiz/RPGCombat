// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/Texture2D.h"
#include "Engine/DataTable.h"
#include "Components/Image.h"
#include "Item.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8 {
	NONE	UMETA(DisplayName = "None"),
	ARMOR	UMETA(DisplayName = "Armor"),
	WEAPON	UMETA(DisplayName = "Weapon"),
	BUILDING_METERIAL	UMETA(DisplayName = "Building Meterial")
};

USTRUCT(BlueprintType)
struct FItem {

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	UClass* ActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	FText ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	UTexture2D* Image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	int32 Quantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	bool bCombinable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	int32 SlotIndex;

};


