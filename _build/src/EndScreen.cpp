#include "Screens.h"

void DrawWinScreen(GameplayManager* game)
{
	DrawTextureEx(game->WinTexture, { -50 ,-250 }, 0, 9, WHITE);	
	//DrawText("Press [START] to go to main menu",200, 300, 20, WHITE);
}

void DrawLoseScreen(GameplayManager* game)
{
	DrawTextureEx(game->GameOverTexture, { -100 ,-350 }, 0,10, WHITE);
	//DrawText("Press [START] to try again", 250, 200, 20, WHITE);
}