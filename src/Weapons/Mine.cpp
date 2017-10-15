#include "Mine.h"
#include <iostream>
#include "../Enemies/Gegner.h"
#include "../Explosion.h"
#include "../ResourceManager/Resources.h"

Mine::Mine(float x, float y) : Entity(x,y)
{
	//Change Body type to a Rect
	body->setCollisionType(t_bullet);
	body->setCollisionWith(t_gegner | t_terrain);
	body->gravMulti = 1.f;
	body->setSize(12.f,4.f);
	Resources::loadTexture(texture,"mine.png");
	sprite.setScale(sf::Vector2f(3.f,3.f));
}



void Mine::tick()
{
	Entity::tick();
}

void Mine::init(Spielfeld * spiel)
{
	Entity::init(spiel);
}

void Mine::collide(Entity * w)
{
	if(w->getBody()->isCollisionType(t_gegner))
	{
		Resources::playSound("mineexplode.wav");
		spielfeld->createObject<Explosion>(body->getPos().x,body->getPos().y);
		body->setCollisionType(t_noCollide);
		body->setCollisionWith(t_noCollide);
		flag_destroy = true;
	}
}

Mine::~Mine()
{

}
