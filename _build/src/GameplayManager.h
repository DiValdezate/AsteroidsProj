#pragma once
#include "Entities.h"

class GameplayManager
{
public:

	Meteor meteors;
	Player player;	
	int gameTime;

	Image playerImg;
	Texture2D playerTexture;
	Image meteorImg;
	Texture2D meteorTexture;

public:

	GameplayManager();
	void LoadTextures();
	void MeteorSpawner();




};

