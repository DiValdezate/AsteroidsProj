#pragma once
#include "raylib.h"
#include <vector>
#include <math.h>

//__________________________________
//INCLUDES ALL CLASSES IN THE GAME
//__________________________________

#define PLAYER_SPEED 3.0f;

class Player
{
	int lives;
	bool alive;
	Vector2 speed;
	Vector2 position;
	Texture2D texture;
	float radius;
	float rotation;
	bool moving;

public:

	Player(int lives);
	Player();

	int GetLives();
	void SetLives(int lives);

	Vector2 GetPosition();
	void SetPosition(Vector2* position);

	Texture2D GetTexture();	
	void SetTexture(Texture2D* texture);

	float GetRotation();
	void SetRotation(float rotation);

	bool isAlive();
	void Kill();
	void Hit();
	void Move(); 
	void TurnLeft();
	void TurnRight();
	void Shoot();
	void Moving(bool value);
	bool IsMoving();

};

class Meteor
{
	bool destroyed;
	Vector2 speed;
	Vector2 position;
	Texture2D texture;
	float radius;
	bool isMoving;


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
	void SetMoving(bool value);
	bool IsMoving();
	void Hit(Texture2D* MediumText, Texture2D* SmallText);
	void GoMedium(Texture2D* texture);
	void GoSmall(Texture2D* texture);
	void Destroy();
	bool IsDestroyed();
};

class Bullet
{
	float radius;
	Vector2 position;
	int timeToDestroy;
	bool active;

public:
	Bullet();

	void CountDown();
	void Destroy();


};





