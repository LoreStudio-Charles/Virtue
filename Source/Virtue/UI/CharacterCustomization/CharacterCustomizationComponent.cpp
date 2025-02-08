#include "CharacterCustomizationComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/Engine.h"

UCharacterCustomizationComponent::UCharacterCustomizationComponent()
{
     PrimaryComponentTick.bCanEverTick = false; // No need to tick for customization.
}

void UCharacterCustomizationComponent::SwapCharacterPart(ECharacterPartType PartType, FName PartID)
{
     // Verify that the character's mesh component is valid.
     if (!CharacterMesh)
     {
          UE_LOG(LogTemp, Error, TEXT("SwapCharacterPart: CharacterMesh is null."));
          return;
     }

     // Check if available parts exist for the given type.
     if (!AvailableParts.Contains(PartType))
     {
          UE_LOG(LogTemp, Error, TEXT("SwapCharacterPart: No available parts for type %d."), (uint8)PartType);
          return;
     }

     // Retrieve the wrapper for available options for the specified part type.
     FCharacterPartOptions& OptionsWrapper = AvailableParts.FindChecked(PartType);

     // Find the option that matches the provided PartID.
     FCharacterPartOption* FoundOption = OptionsWrapper.Options.FindByPredicate([&](const FCharacterPartOption& Option)
          {
               return Option.PartID == PartID;
          });

     if (!FoundOption || !FoundOption->Mesh)
     {
          UE_LOG(LogTemp, Error, TEXT("SwapCharacterPart: Could not find a valid part for type %d with ID '%s'."), (uint8)PartType, *PartID.ToString());
          return;
     }

     // Update the character's skeletal mesh.
     CharacterMesh->SetSkeletalMesh(FoundOption->Mesh);
     UE_LOG(LogTemp, Warning, TEXT("SwapCharacterPart: Updated part type %d to '%s'."), (uint8)PartType, *PartID.ToString());

     // Broadcast the event to notify other systems.
     OnPartUpdated.Broadcast(PartType, PartID);
}
