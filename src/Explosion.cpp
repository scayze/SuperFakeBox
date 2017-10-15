#include "Explosion.h"
#include <iostream>
#include "Spieler.h"
#include "Enemies/Gegner.h"
#include "ParticleSystem/SpriteEmitter.h"

Explosion::Explosion(float x, float y) : Entity(x,y)
{
	//Change Body type to a Rect
	body->setCollisionType(t_noCollide);
	body->setCollisionWith(t_noCollide);
	body->gravMulti = 0.f;
	body->setSize(1.f,1.f);
	radius = 120.f;
	Resources::loadTexture(texture,"explosion.png");
	sprite.setScale(3,3);
	animation = Animation(&sprite,10,55,55,4);
	animation.setRepeat(false);

}

void Explosion::render(sf:: RenderWindow * rW)
{
	rW->draw(*animation.getSprite());
}


void Explosion::tick()
{
	
	Entity::tick();
	std::vector<Entity*> * o = spielfeld->getObjects();
	for(unsigned int i = 0; i < o->size() ;i++)
	{
		if(o->at(i)->getBody()->isCollisionType(t_gegner))
		{
			if(Math::vectorLengthSquared(o->at(i)->getBody()->getPos() - body->getPos()) < radius * radius)
			{
				sf::Vector2f diff = o->at(i)->getBody()->getPos() - body->getPos();
				static_cast<Gegner*>(o->at(i))->dealDamage(10,Math::vectorGetDirection(diff));
			}
		}
	}
	if(animation.isFinished()) flag_destroy = true;
	animation.tick();
	
}

void Explosion::init(Spielfeld * spiel)
{
	Entity::init(spiel);
	spielfeld->screenShake(30);
	std::cout << "GFAFAF";
}
