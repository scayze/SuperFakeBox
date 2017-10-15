#include "Entity.h"

#include <iostream>


Entity::Entity(float x, float y)
{
	//Resources::loadTexture(texture,"bla.png");

	body = new Body();

	body->setPos(x,y);

	flag_destroy = false;
	flag_visible = true;

}

void Entity::init(Spielfeld * spiel)
{
	spielfeld = spiel;
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
	sprite.setScale(3,3);
	body->setOwner(this);
}

void Entity::tick()
{

}

void Entity::render(sf::RenderWindow * rW)
{
	rW->draw(sprite);
}

sf::Sprite& Entity::getSprite()
{
	return sprite;
}

Body * Entity::getBody()
{
	return body;
}

Entity::~Entity()
{
	body->flagDestroy = true;
}

void Entity::collide(Entity * obj)
{

}
