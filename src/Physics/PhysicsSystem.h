#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include <deque>
#include "Body.h"



class PhysicsSystem
{

private:
	std::deque<Body*> bodys;

public:


	void tick();
	void debugRender(sf::RenderWindow * rW);
	void addBody(Body * b);

	bool doCollide(Body * b1, Body *b2);
	void collide(Body * b1, Body *b2);

	bool rectCollide(Body * rect1, Body* rect2);
	bool checkOverlap(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f s1, sf::Vector2f s2);
};

#endif
