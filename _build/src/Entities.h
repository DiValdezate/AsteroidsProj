#pragma once
#include "raylib.h"

class Player
{
	int lives;
	bool alive;
	Vector2 speed;
	Vector2 position;
	Texture2D texture;

public:

	Player(int lives);
	Player();

	int GetLives();
	void SetLives(int lives);

	Vector2 GetPosition();
	void SetPosition(Vector2* position);

	Texture2D GetTexture();	
	void SetTexture(Texture2D* texture);

	bool isAlive();
	void Kill();
	void Hit();
	void Move();

};

class Meteor
{
	bool destroyed;
	Vector2 speed;
	Vector2 position;
	Texture2D texture;


public:
	enum Size
	{
		BIG,
		MEDIUM,
		SMALL
	};

	Size size;

public:

	Meteor();	

	void SetPosition(Vector2* position);
	Vector2 GetPosition();

	void SetSpeed(Vector2* speed);
	Vector2 GetSpeed();

	void SetTexture(Texture2D* texture);
	Texture2D GetTexture();

	void Move();
	void Hit();
	void GoMedium();
	void GoSmall();
	void Destroy();
	bool IsDestroyed();
};







