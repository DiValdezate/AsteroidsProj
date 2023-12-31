#pragma once
#include "Entities.h"


#define MAX_METEORS 25
#define MAX_MET_SIZE 3

//__________________________________
//MANAGES ALL RESOURCES AND THE LOGIC IN THE GAME
//__________________________________

class GameplayManager
{
public:

	int gameTime;
	int invTime;
	int score;
	int timeToWin;

	//TEXTURES
	Image logoImg;
	Texture2D logoTexture;
	Image titleImg;
	Texture2D titleText;
	Image background;
	Texture2D backgroundTexture;
	Image playerImg;
	Texture2D playerTexture;
	Image meteorImg[MAX_MET_SIZE];
	Texture2D meteorTexture[MAX_MET_SIZE];
	Image playerLivesImg[2];
	Texture2D playerLivesTexture[2];
	Image explosionImg;
	Texture2D explosionTexture;
	Image bulletImg;
	Texture2D bulletTexture;
	Image gameOverImg;
	Texture2D gameOverTexture;
	Image winImg;
	Texture2D winTexture;
	Image powerUpImg;
	Texture2D powerUpTexture;

	//AUDIO
	Music menu;
	Music game;
	Music win;
	Music lose;

	Sound shoot;
	Sound enemyHit;
	Sound playerHit;
	

public:

	GameplayManager();
	void LoadTextures();
	void LoadAudio();
	void MeteorSpawner(std::vector<Meteor>* meteors); //Creates a meteor/asteroid in a random position within the screen and stores it in the meteors list
	void MoveMeteors(std::vector<Meteor>* meteors); //Moves every meteor in the meteors vector every frame
	void MoveBullets(std::vector<Bullet>* bullets, float rotation); //Moves every bullet in the bulets vector every frame
	void BulletSpawner(std::vector<Bullet>* bullets, Player* player); //Creates a bullet and stores it in the bullets vector
	void MeteorCollision(std::vector<Meteor>* meteors, Player* player); //Checks meteor collision vs player
	void MeteorCollision(std::vector<Meteor>* meteors, std::vector<Bullet>* bullets); //Checks meteor collision vs bullets
	void PowerUpCollision(PowerUp* powerUp, Player* player);
	int LevelCountDown();
	void InitGame(Player* player, std::vector<Bullet>* bullets, std::vector<Meteor>* meteors, PowerUp* powerup);
	void UnloadTextures();
	void UnloadAudio();
	void PowerUpSpawn(PowerUp* powerUp);
};

