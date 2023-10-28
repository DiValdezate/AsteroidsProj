#include "raylib.h"
#include "Entities.h"
#include "Screens.h"
#include <string>



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
		DrawTextureExCustom(player->GetTexture(), player->GetPosition(), player->GetRotation(), 1, WHITE);		
}

void DrawAsteroids(std::vector<Meteor>* met)//Draws all asteroids at their current posiion
{
	for (int i = 0; i < met->size(); i++)
	{
		Meteor aux = met->at(i);
		if (aux.IsDestroyed() == false)
		{
			DrawTexture(aux.GetTexture(), aux.GetPosition().x - 45, aux.GetPosition().y - 30, WHITE); //Adjusting the texture to allign the center with the position
			//DrawCircle(aux.GetPosition().x, aux.GetPosition().y, aux.GetRadius(), RED);
		}
	}
}

void DrawBullets(std::vector<Bullet>* bullets)
{
	for (int i = 0; i < bullets->size(); i++)
	{
		Bullet aux = bullets->at(i);
		Vector2 auxPos = { aux.GetPosition().x - 12, aux.GetPosition().y - 12}; //Adjusting the texture to allign the center with the position
		DrawTextureEx(aux.GetTexture(), auxPos, 1, 0.25f, WHITE);
		
	}
}

void DrawPowerUp(PowerUp* powerup)
{
	Vector2 correctedPosition = { powerup->GetPosition().x - 50, powerup->GetPosition().y - 50 };
	DrawTextureExCustom(powerup->GetTexture(), correctedPosition,0,2, WHITE);	
	DrawCircle(powerup->GetPosition().x, powerup->GetPosition().y, powerup->GetRadius(), RED);
}

void DrawHUD(GameplayManager* game, Player* player)
{
	char timeText[10];	
	char scoreText[50];

	int playerLives = player->GetLives();

		
	sprintf(timeText, "%d", game->LevelCountDown());
	sprintf(scoreText, "%d", game->score);
	
	DrawText("Survive!", 30, 10, 20, WHITE);
	DrawText(timeText, 125, 10, 20, WHITE);

	DrawText("SCORE: ", 650, 10, 20, WHITE);
	DrawText(scoreText, 750, 10, 20, WHITE);


	switch (playerLives)
	{
	case 3:
		DrawTexture(game->playerLivesTexture[0], 20, 420, WHITE);
		DrawTexture(game->playerLivesTexture[0], 60, 420, WHITE);
		DrawTexture(game->playerLivesTexture[0], 100, 420, WHITE);
	break;

	case 2:
		DrawTexture(game->playerLivesTexture[0], 20, 420, WHITE);
		DrawTexture(game->playerLivesTexture[0], 60, 420, WHITE);
		DrawTexture(game->playerLivesTexture[1], 100, 420, WHITE);
	break;

	case 1:
		DrawTexture(game->playerLivesTexture[0], 20, 420, WHITE);
		DrawTexture(game->playerLivesTexture[1], 60, 420, WHITE);
		DrawTexture(game->playerLivesTexture[1], 100, 420, WHITE);
	break;

	case 0:
		DrawTexture(game->playerLivesTexture[1], 20, 420, WHITE);
		DrawTexture(game->playerLivesTexture[1], 60, 420, WHITE);
		DrawTexture(game->playerLivesTexture[1], 100, 420, WHITE);
	break;
	}
}
