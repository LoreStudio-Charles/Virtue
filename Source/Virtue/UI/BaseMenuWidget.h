#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseMenuWidget.generated.h"

UCLASS()
class VIRTUE_API UBaseMenuWidget : public UUserWidget
{
     GENERATED_BODY()

protected:
     // Fake login state that can be modified by child classes.
     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu")
     bool bIsFakeLoggedIn = false;

     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu")
     bool bIsInGameSession = false;

public:
     virtual void NativeConstruct() override;

     // Declare ToggleFakeLogin as a BlueprintNativeEvent.
     UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Menu")
     void ToggleFakeLogin();
     virtual void ToggleFakeLogin_Implementation();

     // Declare UpdateMenuState as a BlueprintNativeEvent.
     UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Menu")
     void UpdateMenuState();
     virtual void UpdateMenuState_Implementation();

     // Declare UpdateMenuState as a BlueprintNativeEvent.
     UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Menu")
     void QuitGame();
     virtual void QuitGame_Implementation();
};
