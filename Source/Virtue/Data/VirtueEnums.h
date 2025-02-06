// In CharacterCustomizationComponent.h (or in a common header file)
#pragma once

#include "CoreMinimal.h"
#include "CharacterCustomizationComponent.generated.h"

/** Enumerates the different character part types for modular customization. */
UENUM(BlueprintType)
enum class ECharacterPartType : uint8
{
     Head         UMETA(DisplayName = "Head"),
     Hair         UMETA(DisplayName = "Hair"),
     Torso        UMETA(DisplayName = "Torso"),
     Arms         UMETA(DisplayName = "Arms"),
     Legs         UMETA(DisplayName = "Legs"),
     Accessories  UMETA(DisplayName = "Accessories")
};
