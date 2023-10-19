#include "raylib.h"
#include "Entities.h"
#include "Screens.h"



void LoadGameTextures()
{

}


void InitializeEntities()
{
	

}

void DrawTextureExCustom(Texture2D texture, Vector2 position, float rotation, float scale, Color tint)
{
	Rectangle source = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
	Rectangle dest = { position.x, position.y, (float)texture.width * scale, (float)texture.height * scale };
	Vector2 origin = { (float)texture.width / 2.f, (float)texture.height / 2.f };
	DrawTexturePro(texture, source, dest, origin, rotation, tint);
}

void DrawPlayer(Player* player)//Draws the player at the player's current position
{
	if (player->isAlive())
		DrawTextureExCustom(player->GetTexture(), player->GetPosition(), player->GetRotation(), 0.6f, WHITE);		
}

void DrawAsteroids(std::vector<Meteor>* met)//Draws all asteroids at their current posiion
{
	for (int i = 0; i < met->size(); i++)
	{
		Meteor aux = met->at(i);
		if (aux.IsDestroyed() == false)
		{
			DrawTextureEx(aux.GetTexture(), aux.GetPosition(), 1, 1, WHITE);
		}
	}
}
