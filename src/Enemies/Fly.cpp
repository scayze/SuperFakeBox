#include "Fly.h"
#include <iostream>
#include "../Terrain.h"
#include "../ParticleSystem/SpriteEmitter.h"
#include "../Spieler.h"

Fly::Fly(float x, float y) : Gegner(x,y)
{
	Resources::loadTexture(texture,"fly.png");
    speed = 1.5f;
	body->setSize(30.f,21.f);
	hp = 2;
	animation = Animation(&sprite,2,10,7,7);

}

Fly::~Fly()
{
	//if(enraged) feurio->flag_destroy = true;
}

void Fly :: tick()
{
    Gegner::tick();

	if(state == 0)
	{
		body->setVel( Math::vectorNormalize(spielfeld->getPlayer()->getBody()->getPos() - body->getPos()) * speed );
	}

	if(enraged) {
		//feurio->setPosition(sprite.getPosition() - sprite.getOrigin()*1.5f);
		//feurio->setDirection(-Math::vectorGetDirection(sf::Vector2f(body->getVel().x,0)));
	}
}

void Fly::render(sf::RenderWindow * rW)
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

void Fly::init(Spielfeld * feld)
{
	Gegner::init(feld);
	body->setCollisionWith(t_spieler);
	body->gravMulti = 0.f;
	body->setCollisionType(t_gegner);
}

void Fly::enrage()
{


}