#include "GameplayManager.h"
#include <iostream>
#include <string>

GameplayManager::GameplayManager()
{
	gameTime = 0;	
	invTime = 0;

	titleImg = { 0 };
	titleText = { 0 };
	background = { 0 };
	backgroundTexture = { 0 };
	playerImg = { 0 };
	playerTexture = { 0 };
	meteorImg[MAX_MET_SIZE] = {0,0,0};
	meteorTexture[MAX_MET_SIZE] = {0,0,0};
	explosionImg = { 0 };
	explosionTexture = { 0 };
	bulletImg = { 0 };
	bulletTexture = { 0 };

}

void GameplayManager::LoadTextures() //This function loads all textures before the game starts
{
	titleImg = LoadImage("resources/textures/Title.png");
	titleText = LoadTextureFromImage(titleImg);

	background = LoadImage("resources/textures/Landscape.png");
	backgroundTexture = LoadTextureFromImage(background);

	playerImg = LoadImage("resources/textures/Player.png");
	playerTexture = LoadTextureFromImage(playerImg);

	explosionImg = LoadImage("resources/textures/Explosion.png");
	explosionTexture = LoadTextureFromImage(explosionImg);

	bulletImg = LoadImage("resources/textures/Fire.png");
	bulletTexture = LoadTextureFromImage(bulletImg);


	meteorImg[0] = LoadImage("resources/textures/BigMeteor.png");
	meteorImg[1] = LoadImage("resources/textures/MediumMeteor.png");
	meteorImg[2] = LoadImage("resources/textures/SmallMeteor.png");

	meteorTexture[0] = LoadTextureFromImage(meteorImg[0]); //Texture for BIG asteroid.
	meteorTexture[1] = LoadTextureFromImage(meteorImg[1]); //Texture for MEDIUM asteroid.
	meteorTexture[2] = LoadTextureFromImage(meteorImg[2]); //Texture for SMALL asteroid.


}

void GameplayManager::MeteorSpawner(std::vector<Meteor>* meteors)
{	
	Vector2 randomPos = { (float)GetRandomValue(0,450),(float)GetRandomValue(0,850) };
	Meteor met;
	met.SetPosition(&randomPos);
	met.SetTexture(&meteorTexture[0]);
	meteors->push_back(met);
}

void GameplayManager::MoveMeteors(std::vector<Meteor>* meteors)
{
	for (int i = 0; i < meteors->size(); i++)
	{		
		Meteor* aux = &meteors->at(i);
		if (aux->IsDestroyed() == false)
		{
			aux->Move();
		}		
	}
}

void GameplayManager::MoveBullets(std::vector<Bullet>* bullets, float rotation)
{
	for (int i = 0; i < bullets->size(); i++)
	{
		if (bullets->at(i).IsActive())
		{
			bullets->at(i).SetSpeed();
			bullets->at(i).CountDown();			
		}
		else
		{			
			std::vector<Bullet>::iterator it = bullets->begin() + i;
			bullets->erase(it);
		}
	}
}

void GameplayManager::BulletSpawner(std::vector<Bullet>* bullets, Player* player)
{
	Bullet bullet(player->GetRotation());
	bullet.SetPosition(player->GetPosition().x, player->GetPosition().y);
	bullet.SetTexture(&bulletTexture);

	bullets->push_back(bullet);
}

void GameplayManager::MeteorCollision(std::vector<Meteor>* meteors, Player* player)
{	
	for (int i = 0; i < meteors->size(); i++)
	{			
		if (meteors->at(i).CheckCollision(player) && invTime >= 120)
		{
			std::cout << player->GetLives();			
			player->Hit();			
			invTime = 0;
		}
		else
		{
			invTime++;
		}
	}
}

void GameplayManager::MeteorCollision(std::vector<Meteor>* meteors, std::vector<Bullet>* bullets)
{
	for (int i = 0; i < meteors->size(); i++)
	{
		if (meteors->at(i).CheckCollision(bullets))
		{
			meteors->at(i).Destroy();
			std::vector<Meteor>::iterator it = meteors->begin() + i;
			meteors->erase(it);			
		}
	}
}



