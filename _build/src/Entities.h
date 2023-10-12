#pragma once
#include "raylib.h"

class Player
{
	int lives;
	Vector2 position;

public:

	Player(int lives);
	int GetLives();
	void SetLives(int lives);
	void SetPosition(Vector2 position);

	void Hit();
};

class Meteor
{
public:
	enum Size
	{
		BIG,
		MEDIUM,
		SMALL
	};

	Size size;

public:

	Meteor(Size size);

	void Hit();
	void GoMedium();
	void GoSmall();
	void Destroy();

};







