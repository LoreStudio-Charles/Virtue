#include "BaseMenuWidget.h"
#include "Logging/LogMacros.h"

void UBaseMenuWidget::NativeConstruct()
{
     Super::NativeConstruct();
     // Call UpdateMenuState() (this will invoke the implementation in the most derived class)
     UpdateMenuState();
}

void UBaseMenuWidget::ToggleFakeLogin_Implementation()
{
     UE_LOG(LogTemp, Warning, TEXT("UBaseMenuWidget::ToggleFakeLogin_Implementation() called"));
     // Default: do nothing.
}

void UBaseMenuWidget::UpdateMenuState_Implementation()
{
     UE_LOG(LogTemp, Warning, TEXT("UBaseMenuWidget::UpdateMenuState_Implementation() called"));
     // Default: do nothing.
}
