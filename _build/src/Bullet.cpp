#include "Entities.h"

Bullet::Bullet(float rotation)
{
	radius = 5.0f;
	position = { 0 };
	texture = { 0 };
	timeToDestroy = 5 * 60;
	active = true;
	this->rotation = rotation;

}

void Bullet::SetTexture(Texture2D* texture)
{
	this->texture = *texture;
}
Texture2D Bullet::GetTexture()
{
	return texture;
}

float Bullet::GetRadius()
{
	return radius;
}

void Bullet::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

Vector2 Bullet::GetPosition()
{
	return position;
}

void Bullet::CountDown()
{
	timeToDestroy--;
	if (timeToDestroy <= 0)
	{
		Destroy();
	}
}

void Bullet::Destroy()
{
	active = false;
}

bool Bullet::IsActive()
{
	return active;
}

void Bullet::SetSpeed()
{
	
	position.x += sin(this->rotation * DEG2RAD) * BULLET_SPEED;
	position.y -= cos(this->rotation * DEG2RAD) * BULLET_SPEED;
}



