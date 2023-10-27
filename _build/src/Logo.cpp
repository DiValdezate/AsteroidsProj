#include "raylib.h"
#include "Entities.h"
#include "Screens.h"


void InitLogo(Texture2D texture)
{
	DrawTextureEx(texture, { -60,-60 },0,0.6f, WHITE);
}

