#include "Screens.h"

void DrawWinScreen(GameplayManager* game)
{
	DrawTextureEx(game->WinTexture, { -50 ,-250 }, 0, 9, WHITE);
	
}

void DrawLoseScreen(GameplayManager* game)
{
	DrawTextureEx(game->GameOverTexture, { -100 ,-150 }, 0,10, WHITE);	
}