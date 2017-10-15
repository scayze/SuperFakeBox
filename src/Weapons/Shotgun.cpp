#include "Shotgun.h"
#include <iostream>
#include "Bullet.h"
#include "../Spieler.h"

Shotgun::Shotgun(Spielfeld * s) : Weapon(s)
{
	//Change Body type to a Rect
	maxFireDelay = 45;
	name = "Schrotze";
	onePress = true;
	knockback = 5.5;
	screenShakeAmount = 12;
	Resources::loadTexture(tex,"shotgun.png");

}


void Shotgun::shoot(bool right)
{
	Resources::playSound("shotgun.wav");
	applyKnockback(right);
	for(int i=0;i<10;i++)
	{
		Bullet * b = spielfeld->createObject<Bullet>(spr.getPosition().x,spr.getPosition().y);
		b->getBody()->setDecellMulti(1.15);
		b->setDamage(1);
		sf::Vector2f dir = sf::Vector2f(Math::randomFloat(14.f,23.f),0.f);

		float r = Math::randomFloat(-1.f,1.f);

		dir = Math::vectorRotate(dir, r/4);

		if(right) b->getBody()->setVel(dir);
		else b->getBody()->setVel(sf::Vector2f(-dir.x,dir.y));
	}
}
