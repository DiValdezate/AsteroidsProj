#include "Entities.h"
#include "Screens.h"

Player::Player(int lives)
{
	
	this->lives = 3;
	alive = true;
	speed = { 0 };
	position = { (float) GetScreenWidth() / 2,(float) GetScreenHeight() / 2 };
	texture = { 0 };
	radius = 15.0f;
	rotation = 0.0f;
	moving = false;
	tripleShot = false;
}

Player::Player()
{
	lives = 3;
	alive = true;
	speed = { 0 };
	position = { 0 };
	texture = { 0 };
	radius = 15.0f;
	rotation = 0.0f;
	moving = false;
}


int Player::GetLives()
{
	return lives;
}


void Player::SetLives(int lives)
{
	if (lives != NULL)
	{
		this->lives = lives;
	}
}


void Player::SetPosition(Vector2 position)
{
	this->position = position;
}


Vector2 Player::GetPosition()
{
	return position;
}


void Player::SetTexture(Texture2D* texture)
{
	if (texture != NULL)
	{
		this->texture = *texture;
	}
}


Texture2D Player::GetTexture()
{
	return texture;
}


float Player::GetRotation()
{
	return rotation;
}


void Player::SetRotation(float rotation)
{
	this->rotation = rotation;
}


float Player::GetRadius()
{
	return radius;
}


void Player::SetTripleShot(bool value)
{
	tripleShot = value;
}


bool Player::GetTripleShot()
{
	return tripleShot;
}


void Player::Move()
{
	position.x += sin(rotation * DEG2RAD) * PLAYER_SPEED;
	position.y -= cos(rotation * DEG2RAD) * PLAYER_SPEED;	
}


void Player::TurnLeft()
{
	if(moving)
		rotation -= 3.0f;
}


void Player::TurnRight()
{
	if(moving)
		rotation += 3.0f;
}


void Player::Kill()
{
	alive = false;	
}


bool Player::isAlive()
{
	return alive;
}


void Player::Moving(bool value)
{
	this->moving = value;
}


bool Player::IsMoving()
{
	return moving;
}


void Player::Hit()
{
	if (lives > 0)
	{
		SetPosition({ (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 }); //Resets the player's position to the center of the screen
		lives--;

	}
	else
	{
		Kill();
	}
}

