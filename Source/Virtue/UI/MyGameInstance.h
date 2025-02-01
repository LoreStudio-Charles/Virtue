#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

class UUIManager;
class UOnlineSessionManager;

UCLASS()
class VIRTUE_API UMyGameInstance : public UGameInstance
{
     GENERATED_BODY()

public:
     virtual void Init() override;

     UPROPERTY(BlueprintReadOnly, Category = "Managers")
     UUIManager* UIManager;

     UPROPERTY(BlueprintReadOnly, Category = "Managers")
     UOnlineSessionManager* OnlineSessionManager;
};
