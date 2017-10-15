#include "ParticleEmitter.h"
#include <iostream>
#include "../math.h"

ParticleEmitter::ParticleEmitter(sf::Vector2f pos) : position(pos)
{
	density = 0.5f;

	lifetime = 280;
	lifetimeOffset = 0;

	direction = 0;
	spreadAngle = Math::PI() *2;

	flag_destroy = false;

	count = 0;
	direction = 0;
	fadeOut = true;

	localPos = false;

	maxVelocity = 1.f;

	scale = 1.0f;
	scaleOffset = 0.0f;
}


void ParticleEmitter :: tick()
{
	if((float)rand() / (float)RAND_MAX < density)
	{
		addParticle();
	}

	for (unsigned int i = 0; i < particles.size(); i++)
	{
		particles[i].position += particles[i].velocity;
		particles[i].time--;
		if (particles[i].time == 0)
		{
			particles.erase(particles.begin() + i);
		}
	}

	if (count > 0 && particles.empty()) flag_destroy = true;

}

void ParticleEmitter::init()
{
	for (int i = 0; i < count; i++)
	{
		addParticle();
	}
}

void ParticleEmitter::addParticle()
{
	Particle * part = new Particle;

	if(localPos) part->position = sf::Vector2f(0.f,0.f);
	else part->position = position;

	part->size = scale + (float)rand() / (float)RAND_MAX * scaleOffset * 2 - scaleOffset;
	//Whattheflyingfuckwhydoesthisevenworkandhowdidicomeupwiththat
	part->velocity = Math::vectorSetMagnitude(Math::vectorRotate(sf::Vector2f(cos(direction),sin(direction)), (float)rand() / (float)RAND_MAX * spreadAngle * 2 - spreadAngle), (float)rand() / (float)RAND_MAX * maxVelocity);
	part->time = lifetime;
	if(lifetimeOffset>0) part->time += rand() % lifetimeOffset * 2 - lifetimeOffset;
	particles.push_back(*part);
}

void ParticleEmitter::setPosition(sf::Vector2f pos)
{
	position = pos;
}
void ParticleEmitter::setCount(int n)
{
	count = n;
}

void ParticleEmitter::setScale(float n)
{
	scale = n;
}

void ParticleEmitter::setScaleOffset(float n)
{
	scaleOffset = n;
}

void ParticleEmitter::setDensity(float n)
{
	density = n;
}

void ParticleEmitter::setLifetime(int n)
{
	lifetime = n;
}

void ParticleEmitter::setLifetimeOffset(int n)
{
	lifetimeOffset = n;
}

void ParticleEmitter::setMaxVelocity(float v)
{
	maxVelocity = v;
}

void ParticleEmitter::setFadeOut(bool b)
{
	fadeOut = b;
}

void ParticleEmitter::setDirection(float d)
{
	direction = d;
}

void ParticleEmitter::setSpreadAngle(float d)
{
	spreadAngle = d;
}

void ParticleEmitter::setLocalPos(bool d)
{
	localPos = d;
}


ParticleEmitter::~ParticleEmitter()
{

}