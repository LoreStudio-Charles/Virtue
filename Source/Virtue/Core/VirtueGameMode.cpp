#include "VirtueGameMode.h"
#include "Virtue/UI/Main/VirtueHUD.h"

AVirtueGameMode::AVirtueGameMode()
{
     HUDClass = AVirtueHUD::StaticClass();  // Assign the custom HUD
}
