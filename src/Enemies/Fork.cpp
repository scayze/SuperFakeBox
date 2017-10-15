#include "Fork.h"
#include <iostream>
#include "../Terrain.h"
#include "../ParticleSystem/SpriteEmitter.h"

Fork::Fork(float x, float y) : Gegner(x,y)
{
	Resources::loadTexture(texture,"fork.png");
    speed = 4.5;
	body->setSize(20.f,54.f);
	hp = 2;
	animation = Animation(&sprite,5,7,18,10);

}

Fork::~Fork()
{
	if(enraged) feurio->flag_destroy = true;
}

void Fork :: tick()
{
    Gegner::tick();

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

	if(enraged) {
		feurio->setPosition(sprite.getPosition() - sprite.getOrigin()*1.5f);
		feurio->setDirection(-Math::vectorGetDirection(sf::Vector2f(body->getVel().x,0)));
	}
}

void Fork::render(sf::RenderWindow * rW)
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

void Fork::init(Spielfeld * feld)
{
	Gegner::init(feld);
	body->setVel(8,body->getVel().y);
	if (Math::randomInt(0,1)) setSpeed(-getSpeed()); 
	//sprite.setOrigin(sprite.getOrigin() + sf::Vector2f(0,6));
}

void Fork::collide(Entity * o)
{
	if(o->getBody()->isCollisionType(t_terrain))
	{
		if(static_cast<Terrain*>(o)->isWall()) {
			speed = -speed;
		}
	}
}

void Fork::enrage()
{
	speed*=1.5f;
	animation.setSpeed(6.f);
	Resources::loadTexture(texture,"e_fork.png");
	feurio = new SpriteEmitter(sprite.getPosition(),"fire.png");
	feurio->setMaxVelocity(0.35f * fabs(speed));
	feurio->setCount(0);
	feurio->setDirection(Math::PI()*1.5);
	feurio->setSpreadAngle(Math::PI() / 4);
	feurio->setLifetime(35);
	feurio->setScale(2.5f);
	feurio->setLocalPos(true);
	spielfeld->getParticleSystem()->addEmitter(feurio);

}