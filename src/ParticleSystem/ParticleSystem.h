#ifndef ParticleSystem_H
#define ParticleSystem_H

#include "ParticleEmitter.h"

class ParticleSystem
{
private:
	//Container of emitters
	std::vector<ParticleEmitter*> emitters;

public:
	//tick
	void tick();
	//render
	void render(sf::RenderWindow * rW);
	//Function to add an emitter to the system
	void addEmitter(ParticleEmitter* e);
};

#endif