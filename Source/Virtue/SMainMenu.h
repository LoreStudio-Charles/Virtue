#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SMainMenu : public SCompoundWidget
{
public:
     SLATE_BEGIN_ARGS(SMainMenu) {}
     SLATE_END_ARGS()

     /** Constructs this widget with InArgs */
     void Construct(const FArguments& InArgs);
};
