#include "MineDropper.h"
#include <iostream>
#include "Mine.h"


MineDropper::MineDropper(Spielfeld * s) : Weapon(s)
{
	//Change Body type to a Rect
	maxFireDelay = 60;
	name = "DROP IT LIKE ITS HOT";
	screenShakeAmount = 0;
	Resources::loadTexture(tex,"minegun.png");
}


void MineDropper::shoot(bool right)
{
	Resources::playSound("minegun.wav");
	Mine * m = spielfeld->createObject<Mine>(spr.getPosition().x,spr.getPosition().y);
}
