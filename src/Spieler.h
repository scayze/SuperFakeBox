#ifndef SPIELER_H
#define SPIELER_H

#include "Entity.h"

class Weapon;

class Spieler : public Entity
{
	private:
		Weapon * weapon;

		float speed;
		float accell;

		bool lookDirRight;
		int animState;

		Animation animation;
		bool oldDirection;

		int state;

	public:

		Spieler(float x, float y);
		void init(Spielfeld * spiel);
		void tick();
		void render(sf::RenderWindow * rW);

		void die();
		void revive();
		void setWeapon(int w);

		bool isLookDirRight() {return lookDirRight;}

		void collide(Entity *obj);
};

#endif