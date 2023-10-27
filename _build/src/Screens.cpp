#include "raylib.h"
#include "Screens.h"


void BlinkingMessage(int time, char* text)
{
	int aux = 0;
	if (time % 60 == 0)
	{
		DrawText(text, 180, 200, 30, WHITE);
	}
}

void DrawBackground(Texture2D texture)
{
	DrawTextureEx(texture, { 0,0 }, 0, 1, WHITE);
}