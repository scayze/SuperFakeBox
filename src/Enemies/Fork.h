#ifndef FORK_H
#define FORK_H

#include "Gegner.h"

class SpriteEmitter;

class Fork : public Gegner
{
    private:

		SpriteEmitter * feurio;

    public:
        Fork(float x, float y);
		~Fork();
        void tick();
		void init(Spielfeld * spielfeld);
		void collide(Entity * object);
		void render(sf::RenderWindow * rw);
		void enrage();
};

#endif