#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Virtue/UI/Main/MainMenuWidget.h"
#include "Virtue/UI/Main/OptionsMenuWidget.h"
#include "Virtue/UI/CharacterCustomization/CharactersMenuWidget.h"
#include "VirtueGameInstance.generated.h"

class UUIManager;
class UOnlineSessionManager;

UCLASS()
class VIRTUE_API UVirtueGameInstance : public UGameInstance
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
