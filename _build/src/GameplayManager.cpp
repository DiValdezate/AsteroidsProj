#include "GameplayManager.h"
#include "Screens.h"
#include <iostream>
#include <string>

GameplayManager::GameplayManager()
{
	gameTime = 0;	
	invTime = 0;

	score = 0;
	timeToWin = 3600;
	
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
	gameOverImg = { 0 };
	gameOverTexture = { 0 };
	winImg = { 0 };
	winTexture = { 0 };
	powerUpImg = { 0 };
	powerUpTexture = { 0 };

	//AUDIO
	menu = { 0 };
	enemyHit = { 0 };
	playerHit = { 0 };
	game = { 0 };
	lose = { 0 };
	win = { 0 };

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

	powerUpImg = LoadImage("resources/textures/PowerUp.png");
	powerUpTexture = LoadTextureFromImage(powerUpImg);


	meteorImg[0] = LoadImage("resources/textures/BigMeteor.png");
	meteorImg[1] = LoadImage("resources/textures/MediumMeteor.png");
	meteorImg[2] = LoadImage("resources/textures/SmallMeteor.png");

	meteorTexture[0] = LoadTextureFromImage(meteorImg[0]); //Texture for BIG asteroid.
	meteorTexture[1] = LoadTextureFromImage(meteorImg[1]); //Texture for MEDIUM asteroid.
	meteorTexture[2] = LoadTextureFromImage(meteorImg[2]); //Texture for SMALL asteroid.

	gameOverImg = LoadImage("resources/textures/GameOver.png");
	gameOverTexture = LoadTextureFromImage(gameOverImg);
	winImg = LoadImage("resources/textures/Win.png");
	winTexture = LoadTextureFromImage(winImg);


}


void GameplayManager::LoadAudio()
{
	//MUSIC
	menu = LoadMusicStream("resources/Menu.wav");
	game = LoadMusicStream("resources/Game.wav");
	win = LoadMusicStream("resources/Win.wav");
	lose = LoadMusicStream("resources/Lose.wav");

	//EFFECTS
	shoot = LoadSound("resources/Shoot.wav");
	enemyHit = LoadSound("resources/EnemyHit.wav");
	playerHit = LoadSound("resources/PlayerHit.wav");

}


void GameplayManager::MeteorSpawner(std::vector<Meteor>* meteors)
{	
	Vector2 randomPos = { (float)GetRandomValue(0,GetScreenWidth()),(float)GetRandomValue(0,GetScreenHeight()) };
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
			//If the bullet is not active, we erase it from the bullet stack.
			std::vector<Bullet>::iterator it = bullets->begin() + i;
			bullets->erase(it);
		}
	}
}


void GameplayManager::BulletSpawner(std::vector<Bullet>* bullets, Player* player)
{
	if (player->GetTripleShot())
	{
		Bullet bullet1(player->GetRotation());
		Bullet bullet2(player->GetRotation());
		Bullet bullet3(player->GetRotation());
		bullet1.SetPosition(player->GetPosition().x, player->GetPosition().y);
		bullet2.SetPosition(player->GetPosition().x + 10 , player->GetPosition().y);
		bullet3.SetPosition(player->GetPosition().x - 10, player->GetPosition().y);
		bullet1.SetTexture(&bulletTexture);
		bullet2.SetTexture(&bulletTexture);
		bullet3.SetTexture(&bulletTexture);
			
		bullets->push_back(bullet1);
		bullets->push_back(bullet2);
		bullets->push_back(bullet3);
	}
	else
	{
		Bullet bullet(player->GetRotation());
		bullet.SetPosition(player->GetPosition().x, player->GetPosition().y);
		bullet.SetTexture(&bulletTexture);

		bullets->push_back(bullet);
	}
}


void GameplayManager::MeteorCollision(std::vector<Meteor>* meteors, Player* player) //Collision vs player
{	
	invTime++;
	for (int i = 0; i < meteors->size(); i++)
	{			
		if (meteors->at(i).CheckCollision(player) && invTime >= 120) //Only true if it's been at least 2 seconds since the last hit.
		{
			PlaySound(playerHit);						
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
			PlaySound(enemyHit);
			meteors->at(i).Hit(&meteorTexture[1], &meteorTexture[2], score);
			
			if (meteors->at(i).IsDestroyed())
			{
				std::vector<Meteor>::iterator it = meteors->begin() + i;
				meteors->erase(it);
			}
		}
	}
}


void GameplayManager::PowerUpCollision(PowerUp* powerUp, Player* player)
{
	if (CheckCollisionCircles(powerUp->GetPosition(), powerUp->GetRadius(), player->GetPosition(), player->GetRadius()))
	{
		powerUp->SetCollected(true);
		player->SetTripleShot(true);		
	}
}


void GameplayManager::PowerUpSpawn(PowerUp* powerUp)
{
	if (gameTime == 600)
	{
		powerUp->SetPosition({ (float)GetRandomValue(0,700),(float)GetRandomValue(0,300) });
		powerUp->SetTexture(powerUpTexture);
	}
}


int GameplayManager::LevelCountDown() //Returns the remaining time to survive, and if its 0 or less, returns -1, so we know we cleared the game
{
	if (((timeToWin - gameTime) / 60) >= 0)
		return (timeToWin - gameTime) / 60;
	else
		return -1;
}


void GameplayManager::InitGame(Player* player, std::vector<Bullet>* bullets, std::vector<Meteor>* meteors, PowerUp* powerUp)
{
	gameTime = 0;
	invTime = 0;
	score = 0;
	timeToWin = 3600;

	player->SetLives(3);
	player->SetPosition({ (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 });
	player->SetRotation(0.0f);
	player->SetTripleShot(false);
	powerUp->SetPosition({ -10,-10 });
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
	UnloadImage(gameOverImg);
	UnloadImage(winImg);
	UnloadImage(powerUpImg);
	
	UnloadTexture(logoTexture);
	UnloadTexture(titleText);
	UnloadTexture(backgroundTexture);
	UnloadTexture(playerTexture);
	UnloadTexture(bulletTexture);
	UnloadTexture(playerLivesTexture[0]);
	UnloadTexture(playerLivesTexture[1]);
	UnloadTexture(powerUpTexture);
	UnloadTexture(meteorTexture[0]);
	UnloadTexture(meteorTexture[1]);
	UnloadTexture(meteorTexture[2]);
	UnloadTexture(gameOverTexture);
	UnloadTexture(winTexture);	
}


void GameplayManager::UnloadAudio()
{
	UnloadMusicStream(menu);
	UnloadMusicStream(game);
	UnloadMusicStream(win);
	UnloadMusicStream(lose);

	UnloadSound(shoot);
	UnloadSound(enemyHit);
	UnloadSound(playerHit);
}






