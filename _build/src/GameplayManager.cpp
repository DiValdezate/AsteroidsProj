#include "GameplayManager.h"

#define MAX_METEORS 25

GameplayManager::GameplayManager()
{
	gameTime = 0;
	Meteor meteors[MAX_METEORS];
	Player player(3);

	playerImg = { 0 };
	playerTexture = { 0 };
	meteorImg = { 0 };
	meteorTexture = { 0 };

}

void GameplayManager::LoadTextures()
{
	playerImg = LoadImage("resources/textures/Player.png");
	playerTexture = LoadTextureFromImage(playerImg);
}

void GameplayManager::MeteorSpawner()
{

}