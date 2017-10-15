#ifndef MINE_H
#define MINE_H

#include "../Entity.h"

class Mine : public Entity
{
	private:

	public:
		Mine(float x,float y);
		~Mine();
		void init(Spielfeld * spiel);

		void tick();

		void collide(Entity * object);

		void setDamage(int d);

};


#endif
