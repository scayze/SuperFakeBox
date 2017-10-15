#ifndef ROCKET_H
#define ROCKET_H

#include "../Entity.h"

class Rocket : public Entity
{
	private:

	public:
		Rocket(float x,float y);
		~Rocket();
		void init(Spielfeld * spiel);

		void tick();
		void collide(Entity * object);


};


#endif
