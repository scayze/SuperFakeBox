#include "ParticleSystem.h"
#include "ShapeEmitter.h"
#include "SpriteEmitter.h"

void ParticleSystem::render(sf::RenderWindow * rW)
{
	for (unsigned int i = 0; i < emitters.size(); i++)
	{
		emitters[i]->render(rW);
	}
}

void ParticleSystem::tick()
{
	//search and destroy unused emitters
	for (unsigned int i = 0; i < emitters.size(); i++)
	{
		if (emitters[i]->flag_destroy)
		{
			delete emitters[i];
			emitters.erase(emitters.begin() + i);
		}
	}

	//call tick for each emitter
	for (unsigned int i = 0; i < emitters.size(); i++)
	{
		emitters[i]->tick();
	}
}

void ParticleSystem::addEmitter(ParticleEmitter * e)
{
	emitters.push_back(e);
	e->init();
}