#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Virtue/Settings/AssetPaths.h"
#include "MessagesFunctionLibrary.generated.h"

/**
 * UMessagesFunctionLibrary provides helper functions to retrieve UI messages
 * from a central String Table (e.g., ST_UIStrings). This allows you to update
 * texts in one place and support localization easily.
 */
UCLASS()
class VIRTUE_API UMessagesFunctionLibrary : public UBlueprintFunctionLibrary
{
     GENERATED_BODY()

public:
     /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Main Menu !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
     // Returns the localized text for the "Connect" message.
     UFUNCTION(BlueprintPure, Category = "Config | Messages")
     static FText GetConnectText()
     {
          return FText::FromStringTable((* AssetPaths::UIStrings), TEXT("Connect"));
     }

     // Returns the localized text for the "Characters" message.
     UFUNCTION(BlueprintPure, Category = "Config | Messages")
     static FText GetCharactersText()
     {
          return FText::FromStringTable((*AssetPaths::UIStrings), TEXT("Characters"));
     }

     // Returns the localized text for the "Options" message.
     UFUNCTION(BlueprintPure, Category = "Config | Messages")
     static FText GetOptionsText()
     {
          return FText::FromStringTable((*AssetPaths::UIStrings), TEXT("Options"));
     }

     // Returns the localized text for the "Quit" message.
     UFUNCTION(BlueprintPure, Category = "Config | Messages")
     static FText GetQuitText()
     {
          return FText::FromStringTable((*AssetPaths::UIStrings), TEXT("Quit"));
     }

     // Returns the localized text for the "Quit" message.
     UFUNCTION(BlueprintPure, Category = "Config | Messages")
     static FText GetLogoutText()
     {
          return FText::FromStringTable((*AssetPaths::UIStrings), TEXT("Logout"));
     }


     /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Options Menu !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
     // Set the title for the Options Menu
     UFUNCTION(BlueprintPure, Category = "Config | Messages")
     static FText SetOptionsMenuTitleText()
     {
          return FText::FromStringTable((*AssetPaths::UIStrings), TEXT("OptionsMenuTitleText"));
     }
     
     // Returns the localized text for the "Return to Game" message.
     UFUNCTION(BlueprintPure, Category = "Config | Messages")
     static FText GetReturnToGameText()
     {
          return FText::FromStringTable((*AssetPaths::UIStrings), TEXT("ReturnToGame"));
     }

     // Returns the localized text for the "Graphics" message.
     UFUNCTION(BlueprintPure, Category = "Config | Messages")
     static FText GetGraphicsText()
     {
          return FText::FromStringTable((*AssetPaths::UIStrings), TEXT("Graphics"));
     }
     
     // Returns the localized text for the "Audio" message.
     UFUNCTION(BlueprintPure, Category = "Config | Messages")
     static FText GetAudioText()
     {
          return FText::FromStringTable((*AssetPaths::UIStrings), TEXT("Audio"));
     }

     // Returns the localized text for the "Controls" message.
     UFUNCTION(BlueprintPure, Category = "Config | Messages")
     static FText GetControlsText()
     {
          return FText::FromStringTable((*AssetPaths::UIStrings), TEXT("Controls"));
     }


     // Returns the localized text for the "Gameplay" message.
     UFUNCTION(BlueprintPure, Category = "Config | Messages")
     static FText GetGameplayText()
     {
          return FText::FromStringTable((*AssetPaths::UIStrings), TEXT("Gameplay"));
     }

     // Returns the localized text for the "Accessibility" message.
     UFUNCTION(BlueprintPure, Category = "Config | Messages")
     static FText GetAccessibilityText()
     {
          return FText::FromStringTable((*AssetPaths::UIStrings), TEXT("Accessibility"));
     }


     // Returns the localized text for the "Quit to Main Menu" message.
     UFUNCTION(BlueprintPure, Category = "Config | Messages")
     static FText GetQuitToMainMenuText()
     {
          return FText::FromStringTable((*AssetPaths::UIStrings), TEXT("QuitToMainMenu"));
     }


     // Returns the localized text for the "Quit to Desktop" message.
     UFUNCTION(BlueprintPure, Category = "Config | Messages")
     static FText GetQuitToDesktopText()
     {
          return FText::FromStringTable((*AssetPaths::UIStrings), TEXT("QuitToDesktop"));
     }
};
