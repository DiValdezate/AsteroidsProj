#include "Entities.h"
#include "GameplayManager.h"


Meteor::Meteor()
{
	size = BIG;
	destroyed = false;
	InitSpeed();
	position = { 0 };
	texture = { 0 };
	radius = 30.0f;
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
	this->speed.x = speed->x;
	this->speed.y = speed->y;
}

void Meteor::InitSpeed()
{
	int x = GetRandomValue(-2, 2);
	int y = GetRandomValue(-2, 2);

	if (x == 0 && y == 0)
	{
		this->speed.x = 1;
		this->speed.y = 1;
	}
	else
	{
		this->speed.x = x;
		this->speed.y = y;
	}
}

Vector2 Meteor::GetSpeed()
{
	return speed;
}

float Meteor::GetRadius()
{
	return radius;
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
	if (position.x > 0 && position.x <= GetScreenWidth())
		position.x += speed.x;
	else
		position.x += speed.x *=-1;


	if (position.y > 0 && position.y <= GetScreenHeight())
		position.y += speed.y;
	else
		position.y += speed.y *= -1;
}

void Meteor::Hit(Texture2D* MediumText, Texture2D* SmallText, int& score)
{
	switch (size)
	{
	case BIG:
		GoMedium(MediumText);	
		score += 10;
		break;
	case MEDIUM:
		GoSmall(SmallText);
		score += 20;
		break;
	case SMALL:
		score += 30;
		Destroy();
	}
}

bool Meteor::CheckCollision(Player* player)
{
	if (CheckCollisionCircles(position, radius, player->GetPosition(), player->GetRadius()))
	{
		return true;
	}

	return false;
}

bool Meteor::CheckCollision(std::vector<Bullet>* bullets)
{
	for (int i = 0; i < bullets->size(); i++)
	{
		if (CheckCollisionCircles(position, radius, bullets->at(i).GetPosition(), bullets->at(i).GetRadius()))
		{
			//If the meteor hits a bullet, returns true but also destroys the bullet.
			std::vector<Bullet>::iterator it = bullets->begin() + i;
			bullets->erase(it);
			return true;
		}
	}

	return false;
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

