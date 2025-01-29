#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SMainMenuWidget : public SCompoundWidget
{
public:
     SLATE_BEGIN_ARGS(SMainMenuWidget) {}
     SLATE_END_ARGS()

     void Construct(const FArguments& InArgs);
};
