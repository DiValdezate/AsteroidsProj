#include "raylib.h"
#include "Entities.h"
#include "Screens.h"






void InitTitleScreen()
{




}

void DrawTitle(Texture2D title)
{
	Vector2 textPos = { GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 250 };

	

	DrawTextureEx(title, textPos, 0, 2, WHITE);
}
