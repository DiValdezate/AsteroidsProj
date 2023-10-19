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
}

void Bullet::Destroy()
{
	active = false;
}



