#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SMainMenuWidget : public SCompoundWidget
{
public:
     // Defines constructor arguments for the widget (empty in this case)
     SLATE_BEGIN_ARGS(SMainMenuWidget) {}
     SLATE_END_ARGS()

     // Constructs the widget UI
     void Construct(const FArguments& InArgs);

private:
     // Handles Start Game button click
     FReply OnStartGameClicked();

     // Handles Quit button click
     FReply OnQuitClicked();
};
