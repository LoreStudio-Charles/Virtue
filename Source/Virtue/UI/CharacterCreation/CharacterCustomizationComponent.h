#pragma once

#include "CoreMinimal.h"
#include "Engine/SkeletalMesh.h"
#include "Components/ActorComponent.h"
#include "CharacterCustomizationTypes.h"
#include "CharacterCustomizationComponent.generated.h"

// Forward declaration of the SkeletalMeshComponent.
class USkeletalMeshComponent;

/** Delegate to broadcast when a character part is updated. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPartUpdated, ECharacterPartType, PartType, FName, PartID);

/**
 * UCharacterCustomizationComponent manages the modular parts of a character.
 * It stores available options for each part type, swaps parts on request,
 * and broadcasts an event when a part is updated.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class VIRTUE_API UCharacterCustomizationComponent : public UActorComponent
{
     GENERATED_BODY()

public:
     UCharacterCustomizationComponent();

     /**
      * SwapCharacterPart is called to change a specific part of the character.
      * @param PartType - Which part to change (e.g., Head, Torso, etc.)
      * @param PartID - The identifier of the new part option (e.g., "UberCoolHelmet").
      */
     UFUNCTION(BlueprintCallable, Category = "Character Customization")
     void SwapCharacterPart(ECharacterPartType PartType, FName PartID);

     /** Event triggered when a character part is updated. */
     UPROPERTY(BlueprintAssignable, Category = "Character Customization")
     FOnPartUpdated OnPartUpdated;

     /** Available parts mapped by part type.
      *  Using FCharacterPartOptions as the value type allows Blueprint exposure.
      */
     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Customization")
     TMap<ECharacterPartType, FCharacterPartOptions> AvailableParts;

     /** The character’s skeletal mesh component that will be updated when a part is swapped. */
     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Customization")
     USkeletalMeshComponent* CharacterMesh;
};
