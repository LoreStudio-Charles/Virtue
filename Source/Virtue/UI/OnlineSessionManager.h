#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnlineSessionManager.generated.h"

UCLASS(Blueprintable)
class VIRTUE_API UOnlineSessionManager : public UObject
{
     GENERATED_BODY()

public:
     UFUNCTION(BlueprintCallable, Category = "OnlineSession")
     void CreateSession(int32 MaxPlayers = 4);

     UFUNCTION(BlueprintCallable, Category = "OnlineSession")
     void JoinSession(FName SessionName);

     // Add delegates/events for when sessions are created or joined
};
