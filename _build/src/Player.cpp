#include "Entities.h"

Player::Player(int lives)
{
	if (lives != NULL)
	{
		this->lives = 3;
	}
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

void Player::Hit()
{
	if (lives > 0)
	{
		lives--;
	}
}

