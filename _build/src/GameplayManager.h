#pragma once
#include "Entities.h"


#define MAX_METEORS 25
#define MAX_MET_SIZE 3

class GameplayManager
{
public:

	int gameTime;

	Image titleImg;
	Texture2D titleText;
	Image background;
	Texture2D backgroundTexture;
	Image playerImg;
	Texture2D playerTexture;
	Image meteorImg[MAX_MET_SIZE];
	Texture2D meteorTexture[MAX_MET_SIZE];
	Image explosionImg;
	Texture2D explosionTexture;
	Image bulletImg;
	Texture2D bulletTexture;

public:

	GameplayManager();
	void LoadTextures();
	void MeteorSpawner(std::vector<Meteor>* meteors);
	void MoveMeteors(std::vector<Meteor>* meteors);
	void MoveBullets(std::vector<Bullet>* bullets, float rotation);
	void BulletSpawner(std::vector<Bullet>* bullets, Player* player);
};

