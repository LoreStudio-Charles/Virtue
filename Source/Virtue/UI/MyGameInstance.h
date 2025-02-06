#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainMenuWidget.h"
#include "OptionsMenuWidget.h"
#include "Virtue/UI/CharacterCreation/CharactersMenuWidget.h"
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

     UPROPERTY(BlueprintReadOnly, Category = "Config | Managers")
     UUIManager* UIManager;

     UPROPERTY(BlueprintReadOnly, Category = "Config | Managers")
     UOnlineSessionManager* OnlineSessionManager;

     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config | UI")
     TSubclassOf<UMainMenuWidget> MainMenuWidgetClass;

     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config | UI")
     TSubclassOf<UOptionsMenuWidget> OptionsMenuWidgetClass;

     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config | UI")
     TSubclassOf<UCharactersMenuWidget> CharactersMenuWidgetClass;
};
