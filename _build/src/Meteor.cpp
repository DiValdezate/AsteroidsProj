#include "Entities.h"

Meteor::Meteor()
{
	size = BIG;
	destroyed = false;
	speed = { (float)GetRandomValue(-1,2),(float)GetRandomValue(-1,2) };
	position = { 0 };
	texture = { 0 };
	radius = 35.0f;
	isMoving = false;
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

void Meteor::SetMoving(bool value)
{
	this->isMoving = value;
}

bool Meteor::IsMoving()
{
	return isMoving;
}

void Meteor::Move()
{
	position.x += speed.x;
	position.y += speed.y;
}

void Meteor::Hit(Texture2D* MediumText, Texture2D* SmallText)
{
	switch (size)
	{
	case BIG:
		GoMedium(MediumText);
		break;
	case MEDIUM:
		GoSmall(SmallText);
		break;
	case SMALL:
		Destroy();
	}
}

void Meteor::GoMedium(Texture2D* texture) //We need to pass in the Medium texture here
{
	size = MEDIUM;
	this->texture = *texture;	
}

void Meteor::GoSmall(Texture2D* texture) //We need to pass in the Medium texture here
{
	size = SMALL;
	this->texture = *texture;
}

void Meteor::Destroy()
{
	destroyed = true;
}

bool Meteor::IsDestroyed()
{
	return destroyed;
}

