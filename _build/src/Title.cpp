#include "raylib.h"
#include "Entities.h"
#include "Screens.h"

Image titleImg;
Texture2D titleText;

void LoadTextTextures()
{
	titleImg = LoadImage("resources/textures/Title.png");
	titleText = LoadTextureFromImage(titleImg);

}

void DrawTitle(int y)
{
	int limit = -75; //This will stop the title in this position in the Y axis.
	
	Vector2 textPos = { 200, y };

	DrawTextureEx(titleText, textPos, 0, 2, WHITE);

}
