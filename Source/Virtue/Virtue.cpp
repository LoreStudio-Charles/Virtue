#include "Virtue.h"
#include "Modules/ModuleManager.h"
#include "CustomStyle.h" // Include your custom style class

class FVirtueModule : public FDefaultGameModuleImpl
{
     virtual void StartupModule() override
     {
          FCustomStyle::Initialize();  // Initialize custom UI styles
     }

     virtual void ShutdownModule() override
     {
          FCustomStyle::Shutdown();  // Clean up custom UI styles
     }
};

IMPLEMENT_PRIMARY_GAME_MODULE(FVirtueModule, Virtue, "Virtue");
