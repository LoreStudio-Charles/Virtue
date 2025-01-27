#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SMainMenuWidget.h"
#include "VirtueGameMode.generated.h"

UCLASS()
class VIRTUE_API AVirtueGameMode : public AGameModeBase
{
     GENERATED_BODY()

public:
     AVirtueGameMode();

     virtual void StartPlay() override;

protected:
     // Declare the OnStartGame method
     void OnStartGame();
     TSharedPtr<SMainMenuWidget> MyWidget;
};
