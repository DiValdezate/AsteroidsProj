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

//Background image
void DrawBackground(Texture2D texture);

//Logo screen declarations
void InitLogoScreen();
void UpdateLogoScreen();

//Title screen declarations
void InitTitleScreen();
void DrawTitleBackground(Texture2D texture);
void LoadTextTextures();
void DrawTitle(int y, Texture2D texture);

//Gameplay screen declarations
void InitGamePlayScreen();
void LoadGameTextures();
void DrawTextureExCustom(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);
void DrawPlayer(Player* player);
void DrawAsteroids(std::vector<Meteor>* met);
void DrawBullets(std::vector<Bullet>* bullets);
void DrawHUD(GameplayManager* game, Player* player);

//Ending screen declarations
void DrawWinScreen(GameplayManager* game);
void DrawLoseScreen(GameplayManager* game);




