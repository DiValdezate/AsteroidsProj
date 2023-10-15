#include "GameplayManager.h"



GameplayManager::GameplayManager()
{
	gameTime = 0;
	Meteor meteors[MAX_METEORS];
	Player player(3);

	playerImg = { 0 };
	playerTexture = { 0 };
	meteorImg[MAX_MET_SIZE] = {0,0,0};
	meteorTexture[MAX_MET_SIZE] = { 0,0,0 };

}

void GameplayManager::LoadTextures()
{
	playerImg = LoadImage("resources/textures/Player.png");
	playerTexture = LoadTextureFromImage(playerImg);

	meteorImg[0] = LoadImage("resources/textures/BigMeteor.png");
	meteorImg[1] = LoadImage("resources/textures/MediumMeteor.png");
	meteorImg[2] = LoadImage("resources/textures/SmallMeteor.png");
}

void GameplayManager::MeteorSpawner()
{


}