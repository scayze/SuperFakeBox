#ifndef FLY_H
#define FLY_H

#include "Gegner.h"

class SpriteEmitter;

class Fly : public Gegner
{
    private:

		//SpriteEmitter * feurio;

    public:
        Fly(float x, float y);
		~Fly();
        void tick();
		void init(Spielfeld * spielfeld);
		void render(sf::RenderWindow * rw);
		void enrage();
};

#endif