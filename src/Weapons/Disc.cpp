#include "Disc.h"
#include <iostream>
#include "../Enemies/Gegner.h"
#include "../ResourceManager/Resources.h"

Disc::Disc(float x, float y) : Entity(x,y)
{
	//Change Body type to a Rect
	damage = 4;
	body->setCollisionType(t_bullet);
	body->setCollisionWith(t_gegner | t_terrain | t_spieler);
	body->gravMulti = 0.f;
	body->setSize(6.f,1.f);
	Resources::loadTexture(texture,"disc.png");
	sprite.setScale(3,3);
	//Non movable
	wallHit = false;
	speed = 12;
}


void Disc::tick()
{
	Entity::tick();
}

void Disc::init(Spielfeld * spiel)
{
	Entity::init(spiel);	
	if(body->getVel().x != 0) speed = body->getVel().x;
}

void Disc::collide(Entity * w)
{
	if(w->getBody()->isCollisionType(t_gegner))
	{
		dir d;
		if(body->getVel().x > 0) d = DIR_RIGHT;
		else d = DIR_LEFT;
		static_cast<Gegner*>(w)->dealDamage(damage, d);

	}
	if(w->getBody()->isCollisionType(t_terrain))
	{
		if(wallHit) flag_destroy = true;
		else {
			wallHit = true;
			float d = w->getBody()->getPos().x - body->getPos().x;
			body->setVel(-d/fabs(d)*speed,body->getVel().y);
			Resources::playSound("discgun.wav");
		}
	}
	if(w->getBody()->isCollisionType(t_spieler))
	{
		spielfeld->restart();
	}
}

Disc::~Disc()
{

}
