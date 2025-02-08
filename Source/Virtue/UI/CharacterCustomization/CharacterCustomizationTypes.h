#pragma once

#include "CoreMinimal.h"
#include "Engine/SkeletalMesh.h"
#include "CharacterCustomizationTypes.generated.h"

/**
 * Represents one option for a character part (for example, a specific helmet or torso piece).
 */
USTRUCT(BlueprintType)
struct FCharacterPartOption
{
     GENERATED_BODY()

     // Unique identifier for this option (e.g., "UberCoolHelmet").
     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Customization")
     FName PartID;

     // The skeletal mesh to use for this part option.
     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Customization")
     USkeletalMesh* Mesh;
};

/**
 * A wrapper for an array of FCharacterPartOption.
 * Wrapping the TArray in a USTRUCT improves integration with Blueprints.
 */
USTRUCT(BlueprintType)
struct FCharacterPartOptions
{
     GENERATED_BODY()

     // The array of available part options.
     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Customization")
     TArray<FCharacterPartOption> Options;
};
