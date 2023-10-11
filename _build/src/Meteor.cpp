#include "Entities.h"

Meteor::Meteor(Size size)
{
	this->size = size;
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
	//Destroy meteor
}

