#include "raylib.h"
#include "Entities.h"
#include "Screens.h"



void LoadGameTextures()
{

}


void InitializeEntities()
{
	

}

void DrawPlayer(Player* player)//Draws the player at the player's current position
{
	if(player->isAlive())
		DrawTextureEx(player->GetTexture(), player->GetPosition(),1,0.6f, WHITE);
}

