#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Entity.h"

class Explosion : public Entity
{
	private:

		float radius;
		Animation animation;
	public:
		Explosion(float x,float y);
		void init(Spielfeld * spiel);

		void render(sf::RenderWindow * rW);
		void tick();


};


#endif
