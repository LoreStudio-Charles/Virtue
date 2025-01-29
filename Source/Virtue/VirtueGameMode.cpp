#include "VirtueGameMode.h"
#include "Virtue/UI/VirtueHUD.h"

AVirtueGameMode::AVirtueGameMode()
{
     HUDClass = AVirtueHUD::StaticClass();  // Assign the custom HUD
}
