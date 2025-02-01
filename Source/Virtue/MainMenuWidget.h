#pragma once

#include "CoreMinimal.h"
#include "BaseMenuWidget.h"
#include "MainMenuWidget.generated.h"

class UButton;

UCLASS()
class VIRTUE_API UMainMenuWidget : public UBaseMenuWidget
{
     GENERATED_BODY()

public:
     virtual void NativeConstruct() override;

protected:
     // Button references; ensure your Blueprint has these with exactly these names.
     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UButton* ConnectButton;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UButton* LogoutButton;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UButton* CharactersButton;

     // Override ToggleFakeLogin and UpdateMenuState from the base class.
     virtual void ToggleFakeLogin_Implementation() override;
     virtual void UpdateMenuState_Implementation() override;

     // Button click handler functions.
     UFUNCTION()
     void OnConnectButtonClicked();

     UFUNCTION()
     void OnLogoutButtonClicked();

     UFUNCTION()
     void OnCharactersButtonClicked();
};
