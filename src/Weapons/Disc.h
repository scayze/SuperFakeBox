#ifndef DISC_H
#define DISC_H

#include "../Entity.h"

class Disc : public Entity
{
	private:
		int damage;
		bool wallHit;
		
	public:

		float speed;

		Disc(float x,float y);
		~Disc();
		void init(Spielfeld * spiel);

		void tick();
		void setDir(bool right);
		void collide(Entity * object);


};


#endif
