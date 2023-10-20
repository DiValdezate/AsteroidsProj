#include "Entities.h"

Bullet::Bullet()
{
	radius = 5.0f;
	position = { 0 };
	timeToDestroy = 5 * 60;
	active = true;

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

void Bullet::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

void Bullet::SetSpeed(float rotation)
{
	position.x += sin(rotation * DEG2RAD) * BULLET_SPEED;
	position.y -= cos(rotation * DEG2RAD) * BULLET_SPEED;
}



