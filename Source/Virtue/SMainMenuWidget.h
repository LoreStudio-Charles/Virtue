#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

DECLARE_DELEGATE(FStartGameDelegate);

class SMainMenuWidget : public SCompoundWidget
{
public:
     // Defines constructor arguments for the widget (empty in this case)
     SLATE_BEGIN_ARGS(SMainMenuWidget) {}
     SLATE_END_ARGS()

     // Constructs the widget UI
     void Construct(const FArguments& InArgs);

     // The delegate to handle Start Game action
     FStartGameDelegate OnStartGameClickedDelegate;

     // Set this delegate when constructing the widget
     void SetStartGameDelegate(FStartGameDelegate NewDelegate) { OnStartGameClickedDelegate = NewDelegate; }


private:
     // Handles Start Game button click
     FReply OnStartGameClicked();

     // Handles Quit button click
     FReply OnQuitClicked();
};
