#include "Pistol.h"
#include <iostream>
#include "Bullet.h"
#include "../Spieler.h"
Pistol::Pistol(Spielfeld * s) : Weapon(s)
{
	//Change Body type to a Rect
	maxFireDelay = 7;
	name = "Pistuuul";
	onePress = true;
	setKnockback(0.2f);
	screenShakeAmount = 6;
	Resources::loadTexture(tex,"pistol.png");
}


void Pistol::shoot(bool right)
{
	Resources::playSound("pistolshoot.wav");
	applyKnockback(right);
	Bullet * b = spielfeld->createObject<Bullet>(spr.getPosition().x,spr.getPosition().y);
	b->getBody()->setDecellMulti(1);
	b->setDamage(2);
	if(right) b->getBody()->setVel(15,0);
	else b->getBody()->setVel(-15,0);
}
