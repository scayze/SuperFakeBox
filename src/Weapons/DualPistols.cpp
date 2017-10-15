#include "DualPistols.h"
#include <iostream>
#include "Bullet.h"
#include "../Spieler.h"


DualPistols::DualPistols(Spielfeld * s) : Weapon(s)
{
	//Change Body type to a Rect
	maxFireDelay = 7;
	name = "DualPistuul";
	onePress = true;
	screenShakeAmount = 5;
	Resources::loadTexture(tex,"dualpistol.png");
}

void DualPistols::render(sf:: RenderWindow * rW)
{
	setPos(spielfeld->getPlayer()->getBody()->getPos() + sf::Vector2f(0,7));
	rW->draw(spr);
}

void DualPistols::shoot(bool right)
{
	Resources::playSound("pistolshoot.wav");
	Bullet * b1 = spielfeld->createObject<Bullet>(spr.getPosition().x,spr.getPosition().y);
	b1->getBody()->setDecellMulti(1);
	b1->getBody()->setVel(15,0);
	b1->setDamage(1);

	Resources::playSound("pistolshoot.wav");
	Bullet * b2 = spielfeld->createObject<Bullet>(spr.getPosition().x,spr.getPosition().y);
	b2->getBody()->setDecellMulti(1);
	b2->getBody()->setVel(-15,0);
	b2->setDamage(1);
}
