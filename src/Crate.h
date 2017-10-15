#ifndef CRATE_H
#define CRATE_H

#include "Entity.h"

class Crate : public Entity
{
	private:

	public:
		Crate(float x,float y);
		void init(Spielfeld * spiel);

		void render(sf::RenderWindow * rW);
		void tick();
};


#endif
