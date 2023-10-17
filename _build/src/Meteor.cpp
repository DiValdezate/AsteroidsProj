#include "Entities.h"

Meteor::Meteor()
{
	size = BIG;
	destroyed = false;
	speed = { 2,2 };
	position = { 0 };
	texture = { 0 };
}


void Meteor::SetPosition(Vector2* position)
{
	this->position = *position;

}
Vector2 Meteor::GetPosition()
{
	return position;
}

void Meteor::SetTexture(Texture2D* texture)
{
	this->texture = *texture;
}

Texture2D Meteor::GetTexture()
{
	return texture;
}

void Meteor::SetSpeed(Vector2* speed)
{
	this->speed = *speed;
}

Vector2 Meteor::GetSpeed()
{
	return speed;
}

void Meteor::Move()
{
	position.x += speed.x;
	position.y += speed.y;
}

void Meteor::Hit()
{
	switch (size)
	{
	case BIG:
		GoMedium();
		break;
	case MEDIUM:
		GoSmall();
		break;
	case SMALL:
		Destroy();
	}
}

void Meteor::GoMedium()
{
	size = MEDIUM;
}

void Meteor::GoSmall()
{
	size = SMALL;
}

void Meteor::Destroy()
{
	destroyed = true;
}

bool Meteor::IsDestroyed()
{
	return destroyed;
}

