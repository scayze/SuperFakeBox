#include "Bullet.h"
#include <iostream>
#include "../Enemies/Gegner.h"
#include "../ParticleSystem/ParticleSystem.h"
#include "../ParticleSystem/SpriteEmitter.h"

Bullet::Bullet(float x, float y) : Entity(x,y)
{
	//Change Body type to a Rect
	damage = 1;
	body->setCollisionType(t_bullet);
	body->setCollisionWith(t_gegner | t_terrain);
	body->gravMulti = 0.f;
	body->setSize(4.f,4.f);
	Resources::loadTexture(texture,"bullet.png");
	sprite.setScale(3,3);
	//Non movable
	//body->isStatic = true;


}


void Bullet::tick()
{
	Entity::tick();
	if(fabs(Math::vectorLengthSquared(body->getVel())) < 0.05)
	{
		flag_destroy = true;
	}
}

void Bullet::init(Spielfeld * spiel)
{
	Entity::init(spiel);
	
}

void Bullet::collide(Entity * w)
{
	if(w->getBody()->isCollisionType(t_gegner))
	{
		flag_destroy = true;

		dir d;
		if(body->getVel().x > 0) d = DIR_RIGHT;
		else d = DIR_LEFT;
		static_cast<Gegner*>(w)->dealDamage(damage, d);

		spielfeld->screenShake(6);

				SpriteEmitter * burst = new SpriteEmitter(sprite.getPosition(),"BulletImpact.png");
		burst->setMaxVelocity(0.8f);
		burst->setCount(6);
		burst->setSpreadAngle(2.f * Math::PI());
		burst->setLifetime(35);
		burst->setScale(3.f);
		burst->setDensity(0.f);
		spielfeld->getParticleSystem()->addEmitter(burst);

	}
	if(w->getBody()->isCollisionType(t_terrain))
	{
		spielfeld->screenShake(6);
		flag_destroy = true;

		SpriteEmitter * burst = new SpriteEmitter(sprite.getPosition(),"BulletImpact.png");
		burst->setMaxVelocity(0.8f);
		burst->setCount(6);
		burst->setSpreadAngle(2.f * Math::PI());
		burst->setLifetime(35);
		burst->setScale(3.f);
		burst->setDensity(0.f);
		spielfeld->getParticleSystem()->addEmitter(burst);
	}
}

void Bullet::setDamage(int d)
{
	damage = d;
}
Bullet::~Bullet()
{

}
