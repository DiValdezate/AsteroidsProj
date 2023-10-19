#pragma once
#include "Entities.h"


#define MAX_METEORS 25
#define MAX_MET_SIZE 3

class GameplayManager
{
public:

	int gameTime;

	Image playerImg;
	Texture2D playerTexture;
	Image meteorImg[MAX_MET_SIZE];
	Texture2D meteorTexture[MAX_MET_SIZE];
	Image explosionImg;
	Texture2D explosionTexture;

public:

	GameplayManager();
	void LoadTextures();
	void MeteorSpawner(std::vector<Meteor>* meteors);
	void MoveMeteors(std::vector<Meteor>* meteors);
	void MoveBullets(std::vector<Bullet>* bullets);
};

