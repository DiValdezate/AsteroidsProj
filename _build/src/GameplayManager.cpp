#include "GameplayManager.h"
#include "Screens.h"
#include <iostream>
#include <string>

GameplayManager::GameplayManager()
{
	gameTime = 0;	
	invTime = 0;

	score = 0;
	timeToWin = 600;
	
	logoImg = { 0 };
	logoTexture = { 0 };
	titleImg = { 0 };
	titleText = { 0 };
	background = { 0 };
	backgroundTexture = { 0 };
	playerImg = { 0 };
	playerTexture = { 0 };
	meteorImg[MAX_MET_SIZE] = { 0 };
	meteorTexture[MAX_MET_SIZE] = { 0 };
	playerLivesImg[2] = { 0 };
	playerLivesTexture[2] = { 0 };
	explosionImg = { 0 };
	explosionTexture = { 0 };
	bulletImg = { 0 };
	bulletTexture = { 0 };
	GameOverImg = { 0 };
	GameOverTexture = { 0 };
	WinImg = { 0 };
	WinTexture = { 0 };

	//AUDIO
	Menu = { 0 };

}

void GameplayManager::LoadTextures() //This function loads all textures before the game starts
{
	logoImg = LoadImage("resources/textures/splash.png");
	logoTexture = LoadTextureFromImage(logoImg);

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

	playerLivesImg[0] = LoadImage("resources/textures/Life_Active.png");
	playerLivesImg[1] = LoadImage("resources/textures/Life_Inactive.png");

	playerLivesTexture[0] = LoadTextureFromImage(playerLivesImg[0]);
	playerLivesTexture[1] = LoadTextureFromImage(playerLivesImg[1]);


	meteorImg[0] = LoadImage("resources/textures/BigMeteor.png");
	meteorImg[1] = LoadImage("resources/textures/MediumMeteor.png");
	meteorImg[2] = LoadImage("resources/textures/SmallMeteor.png");

	meteorTexture[0] = LoadTextureFromImage(meteorImg[0]); //Texture for BIG asteroid.
	meteorTexture[1] = LoadTextureFromImage(meteorImg[1]); //Texture for MEDIUM asteroid.
	meteorTexture[2] = LoadTextureFromImage(meteorImg[2]); //Texture for SMALL asteroid.

	GameOverImg = LoadImage("resources/textures/GameOver.png");
	GameOverTexture = LoadTextureFromImage(GameOverImg);
	WinImg = LoadImage("resources/textures/Win.png");
	WinTexture = LoadTextureFromImage(WinImg);


}

void GameplayManager::LoadAudio()
{
	Menu = LoadMusicStream("resources/Menu.wav");
	Game = LoadMusicStream("resources/Game.wav");
	Win = LoadMusicStream("resources/Win.wav");
	Lose = LoadMusicStream("resources/Lose.wav");
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


void GameplayManager::MeteorCollision(std::vector<Meteor>* meteors, Player* player) //Collision vs player
{	
	invTime++;
	for (int i = 0; i < meteors->size(); i++)
	{			
		if (meteors->at(i).CheckCollision(player) && invTime >= 120) //Only true if it's been at least 2 seconds since the last hit.
		{
			std::cout << player->GetLives();			
			player->Hit();				
			invTime = 0; //Reset the invulnerability time every hit. 
		}

	}
}

void GameplayManager::MeteorCollision(std::vector<Meteor>* meteors, std::vector<Bullet>* bullets) //Collision vs bullets
{
	for (int i = 0; i < meteors->size(); i++)
	{
		if (meteors->at(i).CheckCollision(bullets))
		{			
			meteors->at(i).Hit(&meteorTexture[1], &meteorTexture[2], score);
			
			if (meteors->at(i).IsDestroyed())
			{
				std::vector<Meteor>::iterator it = meteors->begin() + i;
				meteors->erase(it);
			}
		}
	}
}

int GameplayManager::LevelCountDown() //Returns the remaining time to survive, and if its 0 or less, returns -1, so we know we cleared the game
{
	if (((timeToWin - gameTime) / 60) >= 0)
		return (timeToWin - gameTime) / 60;
	else
		return -1;
}

void GameplayManager::InitGame(Player* player, std::vector<Bullet>* bullets, std::vector<Meteor>* meteors)
{
	gameTime = 0;
	invTime = 0;
	score = 0;
	timeToWin = 600;

	player->SetLives(3);
	player->SetPosition({ (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 });
	player->SetRotation(0.0f);
	bullets->clear();
	meteors->clear();

}

void GameplayManager::UnloadTextures()
{
	UnloadImage(logoImg);
	UnloadImage(titleImg);
	UnloadImage(background);
	UnloadImage(playerImg);
	UnloadImage(meteorImg[0]);
	UnloadImage(meteorImg[1]);
	UnloadImage(meteorImg[2]);
	UnloadImage(playerLivesImg[0]);
	UnloadImage(playerLivesImg[1]);
	UnloadImage(bulletImg);
	UnloadImage(GameOverImg);
	UnloadImage(WinImg);
	
}





