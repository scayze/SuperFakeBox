#ifndef FIRE_H
#define FIRE_H

#include "Entity.h"

class Fire : public Entity
{
	private:
		Animation animation;

	public:
		Fire(float x,float y);
		void init(Spielfeld * spiel);

		void render(sf::RenderWindow * rW);
		void tick();

		void setSize(float w, float h);
		void setSize(sf::Vector2f dim);

		void collide(Entity * object);

};


#endif
