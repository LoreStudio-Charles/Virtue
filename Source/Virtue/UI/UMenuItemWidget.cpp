//#include "UMenuItemWidget.h"
//#include "SMenuItemWidget.h"
//#include "Widgets/SWeakWidget.h"
//#include "Components/Widget.h"
//#include "Components/PanelWidget.h"
//
//void UMenuItemWidget::NativeConstruct()
//{
//     Super::NativeConstruct();
//
//     // Create the Slate widget
//     SlateMenuItem = SNew(SMenuItemWidget)
//          .MenuText(MenuText);
//
//     // Wrap the Slate widget with SWeakWidget to make it UMG-compatible
//     TSharedRef<SWidget> SlateWidgetRef = SNew(SWeakWidget).PossiblyNullContent(SlateMenuItem.ToSharedRef());
//
//     // Find the container (like a CanvasPanel or HorizontalBox) to set the content
//     UPanelWidget* Panel = Cast<UPanelWidget>(GetRootWidget());
//     if (Panel)
//     {
//          // Create an SWidget-based widget to embed within the UMG container
//          UWidget* NewWidget = CreateWidget<UUserWidget>(GetWorld(), UUserWidget::StaticClass());
//          if (NewWidget)
//          {
//               // Embed Slate widget into the new UMG widget
//               NewWidget->SetRootWidget(SlateWidgetRef);
//
//               // Add the new UMG widget to the panel container
//               Panel->AddChild(NewWidget);
//          }
//     }
//}
