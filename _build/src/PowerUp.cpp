#include "Entities.h"
#include "GameplayManager.h"


PowerUp::PowerUp()
{
	position = { 0 };
	isCollected = false;
	texture = { 0 };
	radius = 15.0f;
}

bool PowerUp::IsCollected()
{
	return isCollected;
}

Vector2 PowerUp::GetPosition()
{
	return position;
}

void PowerUp::SetPosition(Vector2 position)
{
	this->position = position;
}

void PowerUp::SetCollected(bool value)
{
	this->isCollected = value;
}

void PowerUp::SetTexture(Texture2D texture)
{
	this->texture = texture;
}

Texture2D PowerUp::GetTexture()
{
	return texture;
}

float PowerUp::GetRadius()
{
	return radius;
}