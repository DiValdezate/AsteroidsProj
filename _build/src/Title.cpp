#include "raylib.h"
#include "Entities.h"
#include "Screens.h"



void DrawTitle(int y, Texture2D texture)
{
	int limit = -75; //This will stop the title in this position in the Y axis.
	
	Vector2 textPos = { 200.0, (float)y };

	DrawTextureEx(texture, textPos, 0, 2, WHITE);
}


