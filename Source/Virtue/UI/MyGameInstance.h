#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainMenuWidget.h"
#include "OptionsMenuWidget.h"
#include "MyGameInstance.generated.h"

/**
* TODO: Comment and explain the process
*/

class UUIManager;
class UOnlineSessionManager;

UCLASS()
class VIRTUE_API UMyGameInstance : public UGameInstance
{
     GENERATED_BODY()

public:
     virtual void Init() override;

     UPROPERTY(BlueprintReadOnly, Category = "Managers")
     UUIManager* UIManager;

     UPROPERTY(BlueprintReadOnly, Category = "Managers")
     UOnlineSessionManager* OnlineSessionManager;

     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
     TSubclassOf<UMainMenuWidget> MainMenuWidgetClass;

     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
     TSubclassOf<UOptionsMenuWidget> OptionsMenuWidgetClass;
};
