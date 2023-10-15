#pragma once
#include "Entities.h"

#define MAX_METEORS 25
#define MAX_MET_SIZE 3

class GameplayManager
{
public:

	Meteor meteors;
	Player player;	
	int gameTime;

	Image playerImg;
	Texture2D playerTexture;
	Image meteorImg[MAX_MET_SIZE];
	Texture2D meteorTexture[MAX_MET_SIZE];

public:

	GameplayManager();
	void LoadTextures();
	void MeteorSpawner();




};

