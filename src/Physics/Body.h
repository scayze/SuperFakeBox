#ifndef BODY_H
#define BODY_H

#include <SFML/Graphics.hpp>
#include "../math.h"
#include <bitset>

enum bodyType
{
	Circle = 0,
	Rect = 1,
};

class Body
{
	protected:

		float decellMulti;

		float width;
		float height;

		unsigned char collisionType;
		unsigned char collisionWith;

		void * owner;

		sf::Vector2f pos;
		sf::Vector2f vel;
		
	public:

		float gravMulti;	
		bool grounded;

		Body();
		Body(float x, float y);

		void tick();
	
		void debugDraw(sf::RenderWindow * rW);

		sf::Vector2f getPos();
		void setPos(float x, float y);
		void setPos(sf::Vector2f vec);

		sf::Vector2f getVel();
		void setVel(float x, float y);
		void setVel(sf::Vector2f vec);

		bool flagDestroy;
		bool isStatic;

		void * getOwner();
		void setOwner(void * o);

		void setDecellMulti(float m);

		unsigned char getCollisionType();
		void setCollisionType(unsigned char byte);

		bool isCollisionType(unsigned char byte);
		unsigned char getCollisionWith();
		void setCollisionWith(unsigned char byte);
		void addCollisionWith(unsigned char byte);

		void setSize(sf::Vector2f size);
		void setSize(float w,float h);
		sf::Vector2f getSize();
};

#endif
