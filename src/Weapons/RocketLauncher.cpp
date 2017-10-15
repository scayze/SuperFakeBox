#include "RocketLauncher.h"
#include <iostream>
#include "Rocket.h"


RocketLauncher::RocketLauncher(Spielfeld * s) : Weapon(s)
{
	//Change Body type to a Rect
	maxFireDelay = 60;
	name = "BOOM";
	screenShakeAmount = 12;
	Resources::loadTexture(tex,"rocketlauncher.png");
}


void RocketLauncher::shoot(bool right)
{
	Resources::playSound("rocketlaunch.wav");
	applyKnockback(right);
	Rocket * b = spielfeld->createObject<Rocket>(spr.getPosition().x,spr.getPosition().y);
	b->getBody()->setDecellMulti(1);
	if(right) b->getBody()->setVel(15,0);
	else b->getBody()->setVel(-15,0);
}
