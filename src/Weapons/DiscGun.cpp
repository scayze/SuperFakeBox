#include "DiscGun.h"
#include <iostream>
#include "Disc.h"


DiscGun::DiscGun(Spielfeld * s) : Weapon(s)
{
	maxFireDelay = 25;
	name = "Fruit Ninja";
	screenShakeAmount = 1;
	Resources::loadTexture(tex,"discgun.png");
}

void DiscGun::shoot(bool right)
{
	float pos_offset;
	if(right) pos_offset = 20,0;
	else pos_offset = -20,0;

	Resources::playSound("discgun.wav");
	applyKnockback(right);
	Disc * b = spielfeld->createObject<Disc>(spr.getPosition().x + pos_offset,spr.getPosition().y);
	b->getBody()->setDecellMulti(1);
	if(right) b->getBody()->setVel(12,0);
	else b->getBody()->setVel(-12,0);
}
