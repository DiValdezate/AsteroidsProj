#pragma once
#include <vector>
#include "GameplayManager.h"

//States of the game
enum GameScreen 
{
	LOGO,
	TITLE,
	GAMEPLAY,
	WIN,
	LOSE
};

//Variable declarations
static GameScreen currentScreen;


//Genral methods declarations
void DrawBackground(Texture2D texture);
void BlinkingMessage(int time, char* text);

//Logo screen declarations
void InitLogo(Texture2D texture);

//Title screen declarations
void DrawTitle(int y, Texture2D texture);

//Gameplay screen declarations
void LoadGameTextures();
void DrawTextureExCustom(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);
void DrawPlayer(Player* player);
void DrawAsteroids(std::vector<Meteor>* met);
void DrawBullets(std::vector<Bullet>* bullets);
void DrawHUD(GameplayManager* game, Player* player);
void DrawPowerUp(PowerUp* powerup);

//Ending screen declarations
void DrawWinScreen(GameplayManager* game);
void DrawLoseScreen(GameplayManager* game);




