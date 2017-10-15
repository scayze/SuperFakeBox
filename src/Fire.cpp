#include "Fire.h"
#include <iostream>
#include "Enemies/Gegner.h"

Fire::Fire(float x, float y) : Entity(x,y)
{
	//Change Body type to a Rect

	body->setCollisionType(t_fire);
	body->setCollisionWith(t_gegner | t_spieler);
	body->gravMulti = 0.f;
	body->setSize(100.f,1.f);
	Resources::loadTexture(texture,"fireplace.png");

	animation = Animation(&sprite,8,22,23,3);
	animation.setRepeat(true);
	sprite.setScale(5.f,3.f);
	//Non movable
	//body->isStatic = true;


}

void Fire::render(sf:: RenderWindow * rW)
{
	Entity::render(rW);
	rW->draw(sprite);
	//Draw only once to background texture of spielfeld
}

void Fire::setSize(float w,float h)
{
	body->setSize(w,h);
	sprite.setOrigin(0,0);
}

void Fire::setSize(sf::Vector2f dim)
{
	body->setSize(dim);
	sprite.setOrigin(0,0);
}


void Fire::tick()
{
	Entity::tick();
	animation.tick();
}

void Fire::init(Spielfeld * spiel)
{
	Entity::init(spiel);
	
}

void Fire::collide(Entity * w)
{
	if(w->getBody()->isCollisionType(t_gegner))
	{
		w->getBody()->setPos(600.f,0.f);
		w->getBody()->setVel(Math::randomInt(-1,1),0.f);
		static_cast<Gegner*>(w)->setEnraged(true);

	}
}
