#include "Rocket.h"
#include <iostream>
#include "../Enemies/Gegner.h"
#include "../Explosion.h"
#include "../ResourceManager/Resources.h"

Rocket::Rocket(float x, float y) : Entity(x,y)
{
	//Change Body type to a Rect
	body->setCollisionType(t_bullet);
	body->setCollisionWith(t_gegner | t_terrain);
	body->gravMulti = 0.f;
	body->setSize(4.f,4.f);
	Resources::loadTexture(texture,"rocket.png");
	sprite.setScale(3,3);
	//Non movable
	//body->isStatic = true;


}


void Rocket::tick()
{
	Entity::tick();
	if(body->getVel().x < 0) sprite.setScale(-3,3);
	else sprite.setScale(3,3);
}

void Rocket::init(Spielfeld * spiel)
{
	Entity::init(spiel);
	
}

void Rocket::collide(Entity * w)
{
	if(w->getBody()->isCollisionType(t_gegner))
	{
		body->setCollisionType(t_noCollide);
		body->setCollisionWith(t_noCollide);
		flag_destroy = true;
		spielfeld->createObject<Explosion>(body->getPos().x,body->getPos().y);
	}
	if(w->getBody()->isCollisionType(t_terrain))
	{
		flag_destroy = true;
		body->setCollisionType(t_noCollide);
		body->setCollisionWith(t_noCollide);
		spielfeld->createObject<Explosion>(body->getPos().x,body->getPos().y);
	}
	Resources::playSound("rocketexplode.wav");
}

Rocket::~Rocket()
{

}
