#include "PhysicsSystem.h"
//#include "../Entity.h"
#include "../Spieler.h"
#include <iostream>

void PhysicsSystem::addBody(Body * b)
{
	if (!b->isStatic)
		bodys.push_front(b);
	else bodys.push_back(b);
}

void PhysicsSystem::debugRender(sf::RenderWindow * rW)
{
	for (unsigned int i = 0; i < bodys.size(); i++)
	{
		bodys[i]->debugDraw(rW);

	}
}

void PhysicsSystem::tick()
{
	for (unsigned int i = 0; i < bodys.size(); i++)
	{
		if (bodys[i]->flagDestroy)
		{
			delete bodys[i];
			bodys.erase(bodys.begin() + i);
		}
	}

	//Loop durch alle K�rper
	for (unsigned int i = 0; i < bodys.size(); i++)
	{
		//Wenn es ein statischer k�rper ist, breche ab
		if (bodys[i]->isStatic) break;

		//Loop durch alle anderen K�rper
		for (unsigned int j = i + 1; j < bodys.size(); j++)
		{
			//Wenn die K�rper nicht Kollidieren sollen, gehe zur n�chsten loop iteration
			if (!doCollide(bodys[i], bodys[j])) continue;

			bool collided;
			collided = rectCollide(bodys[i], bodys[j]);

			//Wenn pushvektor nicht 0 ist, dann lasse sie kollidieren
			if (collided) collide(bodys[i], bodys[j]);

		}
	}

	for (unsigned int i = 0; i < bodys.size(); i++)
	{
		if (!bodys[i]->isStatic) bodys[i]->tick();
	}
}

void PhysicsSystem::collide(Body * b1, Body * b2)
{
	//Let the Objects know they are colliding
	Entity * w1 = static_cast<Entity*>(b1->getOwner());
	Entity * w2 = static_cast<Entity*>(b2->getOwner());

	if (w1 && w2)
	{
		w1->collide(w2);
		w2->collide(w1);
	}

}

bool PhysicsSystem::doCollide(Body * b1, Body *b2)
{
	return (b1->getCollisionType() & b2->getCollisionWith()) | (b1->getCollisionWith() & b2->getCollisionType());
}

bool PhysicsSystem::checkOverlap(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f s1, sf::Vector2f s2)
{
	//Betrag X-Abstand * 2		//Kleiner als die breiten addiert
	return fabs(p1.x - p2.x) * 2 < (s1.x + s2.x) && fabs(p1.y - p2.y) * 2 < (s1.y + s2.y);
}

bool PhysicsSystem::rectCollide(Body* a, Body* b)
{
	Body * b1 = nullptr;
	Body * b2 = nullptr;
	if(a->isCollisionType(t_terrain)) {
		b1 = b;
		b2 = a;
	}
	else if(b->isCollisionType(t_terrain)) {
		b1 = a;
		b2 = b;
	}

	bool collided = checkOverlap(a->getPos() + a->getVel(),b->getPos() + b->getVel() ,a->getSize(),b->getSize());

	if( b1 == nullptr )
	{
		return collided;
	}
	else if(collided)
	{
		
		sf::Vector2f p1 = b1->getPos();
		sf::Vector2f p2 = b2->getPos();
		sf::Vector2f diff = p1 - p2;
		sf::Vector2f moveBy;

		float distance;

		if(abs( abs(diff.x) - (b1->getSize().x / 2 + b2->getSize().x / 2)) < abs(abs(diff.y) - (b1->getSize().y / 2 + b2->getSize().y / 2)))
		{
			distance = (b1->getSize().x/2 + b2->getSize().x/2) - fabs(diff.x);
			if(diff.x < 0)
			{
				moveBy = sf::Vector2f(1,0);
			}
			else
			{
				moveBy = sf::Vector2f(-1,0);
			}
		}
		else
		{
			distance = (b1->getSize().y/2 + b2->getSize().y/2) - fabs(diff.y);
			if(diff.y < 0)
			{
				moveBy = sf::Vector2f(0,1);
				b1->grounded = true;
			}
			else
			{
				moveBy = sf::Vector2f(0,-1);
			}
		}

		b1->setPos(b1->getPos() - moveBy * distance);
		b1->setVel(sf::Vector2f(b1->getVel().x * fabs(moveBy.y), b1->getVel().y * fabs(moveBy.x)));
		return true;
	}

	return false;
}