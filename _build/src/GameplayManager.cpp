#include "GameplayManager.h"



GameplayManager::GameplayManager()
{
	gameTime = 0;	
	
	playerImg = { 0 };
	playerTexture = { 0 };
	meteorImg[MAX_MET_SIZE] = {0,0,0};
	meteorTexture[MAX_MET_SIZE] = {0,0,0};

}

void GameplayManager::LoadTextures()
{
	playerImg = LoadImage("resources/textures/Player.png");
	playerTexture = LoadTextureFromImage(playerImg);

	meteorImg[0] = LoadImage("resources/textures/BigMeteor.png");
	meteorImg[1] = LoadImage("resources/textures/MediumMeteor.png");
	meteorImg[2] = LoadImage("resources/textures/SmallMeteor.png");

	meteorTexture[0] = LoadTextureFromImage(meteorImg[0]); //Texture for BIG asteroid.
	meteorTexture[1] = LoadTextureFromImage(meteorImg[1]); //Texture for MEDIUM asteroid.
	meteorTexture[2] = LoadTextureFromImage(meteorImg[2]); //Texture for SMALL asteroid.


}

void GameplayManager::MeteorSpawner(std::vector<Meteor>* meteors)
{	
	if (meteors->size() == 0)
	{
		for (int i = 0; i < 5; i++)
		{
			Vector2 randomPos = { GetRandomValue(-100,600),GetRandomValue(-150,900) };
			Meteor met;
			met.SetPosition(&randomPos);
			met.SetTexture(&meteorTexture[0]);
			meteors->push_back(met);
		}
	}
	Vector2 randomPos = { GetRandomValue(0,450),GetRandomValue(0,850) };
	Meteor met;
	met.SetPosition(&randomPos);
	met.SetTexture(&meteorTexture[0]);
	meteors->push_back(met);
}

void GameplayManager::MoveMeteors(std::vector<Meteor>* meteors)
{
	for (int i = 0; i < meteors->size(); i++)
	{
		Meteor aux = meteors->at(i);
		if (aux.IsDestroyed() != false)
		{

		}
	}
}

