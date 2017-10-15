#include "Crate.h"
#include <iostream>
#include "Spieler.h"


Crate::Crate(float x, float y) : Entity(x,y)
{
	//Change Body type to a Rect

	body->setCollisionType(t_crate);
	body->setCollisionWith(t_spieler | t_terrain);
	body->gravMulti = 0.f;
	body->setSize(21.f,33.f);
	Resources::loadTexture(texture,"maggi.png");
	sprite.setScale(sf::Vector2f(3.f,3.f));
	//Non movable
	//body->isStatic = true;


}

void Crate::render(sf:: RenderWindow * rW)
{
	Entity::render(rW);
}

void Crate::tick()
{
	Entity::tick();
}

void Crate::init(Spielfeld * spiel)
{
	Entity::init(spiel);
	sprite.setOrigin(sprite.getOrigin());
	//Resources::loadTexture(*spE->getTexture(), "explosion.png");
	//spielfeld->getParticleSystem()->addEmitter(spE);
	
}
