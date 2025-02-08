#pragma once

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"

// Macro to bind a button's OnClicked event using the given class name.
// Example usage:
//     BIND_BUTTON(UMainMenuWidget, ConnectButton, OnConnectButtonClicked);
#define BIND_BUTTON(ClassName, Button, Handler)              \
    if (Button)                                              \
    {                                                        \
        Button->OnClicked.RemoveDynamic(this, &ClassName::Handler); \
        Button->OnClicked.AddDynamic(this, &ClassName::Handler);    \
    }

// Namespace to encapsulate common UI helper functions.
namespace UIHelpers
{
     // Inline helper function to set localized text on a UTextBlock.
     FORCEINLINE void SetLocalizedText(UTextBlock* TextBlock, const FText& Text)
     {
          if (TextBlock)
          {
               TextBlock->SetText(Text);
          }
     }

     // Inline helper function to set a button's visibility.
     FORCEINLINE void SetButtonVisibility(UButton* Button, bool bVisible)
     {
          if (Button)
          {
               Button->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
          }
     }
}
