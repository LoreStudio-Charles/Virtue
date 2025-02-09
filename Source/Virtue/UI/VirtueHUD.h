#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "VirtueHUD.generated.h"

/**
 * A minimal HUD class that delegates UI creation to the UIManager subsystem.
 */
UCLASS()
class VIRTUE_API AVirtueHUD : public AHUD
{
     GENERATED_BODY()

public:
     AVirtueHUD();

     // Called when the game starts or when spawned.
     virtual void BeginPlay() override;
};
