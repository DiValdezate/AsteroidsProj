#include "Entities.h"

Player::Player(int lives)
{
	if (lives != NULL)
	{
		this->lives = 3;
	}

	alive = true;
	speed = { 1,1 };
	position = { 0 };
	texture = { 0 };
}

Player::Player()
{
	lives = 3;
	alive = true;
	speed = { 1,1 };
	position = { 0 };
	texture = { 0 };
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

void Player::SetPosition(Vector2* position)
{
	this->position = *position;
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

void Player::Move()
{
	position.x += speed.x;
	position.y += speed.y;
}
void Player::Kill()
{
	alive = false;	
}

bool Player::isAlive()
{
	return alive;
}

void Player::Hit()
{
	if (lives > 0)
	{
		lives--;
	}
}

