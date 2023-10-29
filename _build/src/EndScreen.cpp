#include "Screens.h"

void DrawWinScreen(GameplayManager* game)
{
	DrawTextureEx(game->winTexture, { 300 ,0 }, 0, 3, WHITE);

}

void DrawLoseScreen(GameplayManager* game)
{
	DrawTextureEx(game->gameOverTexture, { -100 ,-350 }, 0,10, WHITE);
	
}