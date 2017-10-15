#include "Gegner.h"
#include <iostream>
#include "../Terrain.h"
#include "../ResourceManager/Resources.h"

Gegner::Gegner(float x, float y) : Entity(x,y)
{
    sprite.setTexture(texture);
    sprite.setPosition(x,y);
    speed = 4.5;
	enraged = false;
	body->setSize(20.f,54.f);
	//flag_visible = false;
	hp = 2;
	state = 0;
	animation = Animation(&sprite,5,7,18,15);

}

Gegner::~Gegner()
{
}

void Gegner :: tick()
{
    Entity::tick();

	if(state == 0)
	{
		if (fabs(body->getVel().x) != speed)
		{
			if(body->getVel().x < 0.0000f) {
				body->setVel(-speed,body->getVel().y);
			}
			if(body->getVel().x >= 0.0000f) {
				body->setVel(speed,body->getVel().y);
			}
		}
	}
	else if(state == 1)
	{
		sprite.setRotation(Math::vectorGetRotation(body->getVel()) / Math::PI() * 180 + 90);
	}

	if(!sf::FloatRect(sf::Vector2f(0.f,0.f),sf::Vector2f(spielfeld->getRenderWindow()->getSize().x,spielfeld->getRenderWindow()->getSize().y)).contains(body->getPos()))
	{
		flag_destroy = true;
	}
	animation.tick();
}

void Gegner::render(sf::RenderWindow * rW)
{
	bool lookDirRight = body->getVel().x > 0;
    if(lookDirRight != oldDirection)
    {
		if(lookDirRight) sprite.setScale(sf::Vector2f(3,3));
		else sprite.setScale(sf::Vector2f(-3,3));
	    oldDirection = lookDirRight;
    }

    rW->draw(*animation.getSprite());
}

void Gegner::init(Spielfeld * feld)
{
	Entity::init(feld);
	body->setCollisionWith(t_terrain | t_spieler);
	body->gravMulti = 1.f;
	body->setCollisionType(t_gegner);
	body->setVel(8,body->getVel().y);
}

void Gegner::die(dir d = DIR_NONE)
{
	Resources::playSound("DEATH10.wav");
	state = 1;

	if(d==DIR_LEFT) body->setVel(-10,-10);
	else if(d==DIR_RIGHT) body->setVel(10,-10);
	else if(d==DIR_DOWN) body->setVel(10,0);
	else body->setVel(0,-15);

	body->setCollisionWith(t_noCollide);
	body->setCollisionType(t_noCollide);
	body->setDecellMulti(1.01f);
	body->gravMulti = 2.f;
}

void Gegner::setSpeed(float s)
{
	speed = s;
}

float Gegner::getSpeed()
{
	return speed;
}

void Gegner::setEnraged(bool r)
{
	if(r && !enraged) 
	{
		enraged = r;
		enrage();
	}
}

bool Gegner::getEnraged()
{
	return enraged;
}

void Gegner::dealDamage(int a, dir d)
{
	hp-= a;
	if(hp<=0) die(d);
}