#include "Weapon.h"
#include <iostream>
#include "../Spieler.h"

Weapon::Weapon(Spielfeld * s)
{

	fireDelay = 0;
	spielfeld = s;
	onePress = false;
	knockback = 4.f;
	screenShakeAmount = 10;
	spr.setScale(3,3);
	//Resources::loadTexture(tex,"explosion.png");
	

}

void Weapon::render(sf:: RenderWindow * rW)
{
	bool lookDirRight = spielfeld->getPlayer()->isLookDirRight();
	if(lookDirRight)	setPos(spielfeld->getPlayer()->getBody()->getPos() + sf::Vector2f(25,7));
	else				setPos(spielfeld->getPlayer()->getBody()->getPos() + sf::Vector2f(-25,7));
	rW->draw(spr);
}

void Weapon::pressTrigger(bool right)
{
	if(fireDelay <= 0)
	{
		shoot(right);
		spielfeld->screenShake(screenShakeAmount);
		fireDelay = maxFireDelay;
	}
}

void Weapon::tick()
{
	fireDelay--;
}

void Weapon::applyKnockback(bool right)
{
	if(right) spielfeld->getPlayer()->getBody()->setVel(spielfeld->getPlayer()->getBody()->getVel() + sf::Vector2f(-knockback,0));
	else spielfeld->getPlayer()->getBody()->setVel(spielfeld->getPlayer()->getBody()->getVel() + sf::Vector2f(knockback,0));
}


void Weapon::setKnockback(float kb)
{
    knockback = kb;
}

void Weapon::setDir(bool kb)
{
	spr.setTexture(tex);
    right = kb;
	if(right) {
		//spr.setOrigin(-10,0);
		spr.setScale(3,3);
	}
	else {
		//spr.setOrigin(10,0);
		spr.setScale(-3,3);
	}
	spr.setOrigin(sf::Vector2f(spr.getLocalBounds().width/2,spr.getLocalBounds().height/2));
}
