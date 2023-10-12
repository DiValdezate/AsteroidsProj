#include "raylib.h"
#include "Entities.h"
#include "Screens.h"






void InitTitleScreen()
{




}

void DrawTitle(Texture2D title, int y)
{
	int limit = -75; //This will stop the title in this position in the Y axis.
	
	if (y < limit)
	{
		Vector2 textPos = { 200, y };

		DrawTextureEx(title, textPos, 0, 2, WHITE);
	}
	

	
}
