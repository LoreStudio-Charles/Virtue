#include "MyGameInstance.h"
#include "UIManager.h"
#include "OnlineSessionManager.h"

void UMyGameInstance::Init()
{
     Super::Init();

     // Create our managers (could be UObject-based classes)
     UIManager = NewObject<UUIManager>(this, UUIManager::StaticClass());
     OnlineSessionManager = NewObject<UOnlineSessionManager>(this, UOnlineSessionManager::StaticClass());

     // Optionally, initialize these managers here
     // UIManager->Initialize(...);
     // OnlineSessionManager->Initialize(...);
}
