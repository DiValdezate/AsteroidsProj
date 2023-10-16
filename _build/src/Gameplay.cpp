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
		DrawTextureEx(player->GetTexture(), player->GetPosition(), 1, 0.6f, WHITE);
}

void DrawAsteroids(std::vector<Meteor>* met)//Draws all asteroids at their current posiion
{
	for (int i = 0; i < met->size(); i++)
	{
		Meteor aux = met->at(i);
		if (aux.IsDestroyed() != false)
		{
			DrawTextureEx(aux.GetTexture(), aux.GetPosition(), 1, 0.6f, WHITE);
		}

	}


}
