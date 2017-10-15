#include "MassiveFork.h"
#include <iostream>
#include "../Terrain.h"
#include "../ParticleSystem/SpriteEmitter.h"

MassiveFork::MassiveFork(float x, float y) : Gegner(x,y)
{
	Resources::loadTexture(texture,"m_fork.png");
    speed = 3.85678f;
	body->setSize(36.f,72.f);
	hp = 4;
	animation = Animation(&sprite,5,12,24,6);

}

MassiveFork::~MassiveFork()
{
	if(enraged) feurio->flag_destroy = true;
}

void MassiveFork :: tick()
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

void MassiveFork::render(sf::RenderWindow * rW)
{
	bool lookDirRight = body->getVel().x > 0;
    if(lookDirRight != oldDirection)
    {
		if(lookDirRight) sprite.setScale(sf::Vector2f(3.f,3.f));
		else sprite.setScale(sf::Vector2f(-3.f,3.f));
	    oldDirection = lookDirRight;
    }

    rW->draw(*animation.getSprite());
}

void MassiveFork::init(Spielfeld * feld)
{
	Gegner::init(feld);
	body->setVel(8,body->getVel().y);
	if (Math::randomInt(0,1)) setSpeed(-getSpeed()); 
	//sprite.setOrigin(sprite.getOrigin() + sf::Vector2f(0,6));
}

void MassiveFork::collide(Entity * o)
{
	if(o->getBody()->isCollisionType(t_terrain))
	{
		if(static_cast<Terrain*>(o)->isWall()) {
			speed = -speed;
		}
	}
}

void MassiveFork::enrage()
{
	speed*=1.5f;
	animation.setSpeed(6.f);
	Resources::loadTexture(texture,"e_m_fork.png");
	feurio = new SpriteEmitter(sprite.getPosition(),"fire.png");
	feurio->setMaxVelocity(0.35f * fabs(speed));
	feurio->setCount(0);
	feurio->setSpreadAngle(2.f * Math::PI());
	feurio->setLifetime(35);
	feurio->setScale(2.5f);
	feurio->setLocalPos(true);
	spielfeld->getParticleSystem()->addEmitter(feurio);

}