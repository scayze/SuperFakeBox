#ifndef MASSIVEFORK_H
#define MASSIVEFORK_H

#include "Gegner.h"

class SpriteEmitter;

class MassiveFork : public Gegner
{
    private:

		SpriteEmitter * feurio;

    public:
        MassiveFork(float x, float y);
		~MassiveFork();
        void tick();
		void init(Spielfeld * spielfeld);
		void collide(Entity * object);
		void render(sf::RenderWindow * rw);
		void enrage();
};

#endif