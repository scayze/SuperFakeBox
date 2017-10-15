#ifndef BULLET_H
#define BULLET_H

#include "../Entity.h"

class Bullet : public Entity
{
	private:
		int damage;
	public:
		Bullet(float x,float y);
		~Bullet();
		void init(Spielfeld * spiel);

		void tick();

		void collide(Entity * object);

		void setDamage(int d);

};


#endif
