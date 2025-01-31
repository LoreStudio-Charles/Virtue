#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MenuDataStructs.generated.h"

// Structure for DT_Menus
USTRUCT(BlueprintType)
struct FMenuData : public FTableRowBase
{
     GENERATED_BODY()

     UPROPERTY(EditAnywhere, BlueprintReadWrite)
     FName MenuID;

     UPROPERTY(EditAnywhere, BlueprintReadWrite)
     FText MenuName;

     UPROPERTY(EditAnywhere, BlueprintReadWrite)
     UTexture2D* BackgroundImage;
};

// Structure for DT_MenuItems
USTRUCT(BlueprintType)
struct FMenuItemData : public FTableRowBase
{
     GENERATED_BODY()

     UPROPERTY(EditAnywhere, BlueprintReadWrite)
     FName MenuID;

     UPROPERTY(EditAnywhere, BlueprintReadWrite)
     FText ButtonName;

     UPROPERTY(EditAnywhere, BlueprintReadWrite)
     FName ActionType;

     UPROPERTY(EditAnywhere, BlueprintReadWrite)
     FName ActionValue;
};
