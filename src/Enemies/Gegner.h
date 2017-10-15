#ifndef Gegner_H
#define Gegner_H

#include "../Entity.h"

class Gegner : public Entity
{
    protected:
		float speed;
		float hp;
		bool enraged;
		int state;
		Animation animation;
		bool oldDirection;

    public:
        Gegner(float x, float y);
		~Gegner();
        virtual void tick();
		virtual void init(Spielfeld * spielfeld);
		virtual void render(sf::RenderWindow * rw);
		void die(dir d);

		virtual void enrage() = 0;
		void setSpeed(float s);
		float getSpeed();
		void setEnraged(bool r);
		bool getEnraged();
		void dealDamage(int a, dir d = DIR_NONE);
};

#endif