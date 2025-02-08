#include "Virtue.h"
#include "Modules/ModuleManager.h"

class FVirtueModule : public FDefaultGameModuleImpl
{
     virtual void StartupModule() override
     {
          // Initialization code (empty for now)
     }

     virtual void ShutdownModule() override
     {
          // Cleanup code (empty for now)
     }
};

IMPLEMENT_PRIMARY_GAME_MODULE(FVirtueModule, Virtue, "Virtue");
