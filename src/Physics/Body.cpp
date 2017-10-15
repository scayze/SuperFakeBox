#include "Body.h"


Body::Body()
{
	pos.x = 0;
	pos.y = 0;
	isStatic = false;
	owner = NULL;
	collisionType = 0x0000000;
	collisionWith = 0x0000000;
	flagDestroy = false;
	gravMulti = 1.f;
	grounded = false;
	decellMulti = 1.1f;

	width = 10;
	height = 10;
}

Body::Body(float xpos,float ypos)
{
	pos.x = xpos;
	pos.y = ypos;
	owner = NULL;
}

void Body::tick()
{
	pos+=vel;

	vel.x /= decellMulti;
	if(gravMulti == 0.f) vel.y /= 1.2f;
	vel.y += 0.35f * gravMulti;
}

void Body::debugDraw(sf::RenderWindow * rW)
{
	sf::RectangleShape rec;
	rec.setPosition(pos-getSize()/2.f);
	rec.setOutlineThickness(2);
	rec.setFillColor(sf::Color::Transparent);
	rec.setOutlineColor(sf::Color::Yellow);
	rec.setSize(getSize());

	//rW->draw(rec);
}

sf::Vector2f Body::getSize()
{
	return sf::Vector2f(width,height);
}

void Body::setSize(sf::Vector2f s)
{
	width = s.x;
	height = s.y;
}

void Body::setSize(float w, float h)
{
	width = w;
	height = h;
}


//Position get & sets
sf::Vector2f Body::getPos()
{
    return pos;
}

void Body::setPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
}

void Body::setPos(sf::Vector2f vec)
{
	pos.x = vec.x;
	pos.y = vec.y;
}

void Body::setDecellMulti(float m)
{
	decellMulti = m;
}

//Velocity get & sets
sf::Vector2f Body::getVel()
{
    return vel;
}

void Body::setVel(float x, float y)
{
	vel.x = x;
	vel.y = y;
}

void Body::setVel(sf::Vector2f vec)
{
	vel.x = vec.x;
	vel.y = vec.y;
}

void * Body::getOwner()
{
	return owner;
}

void Body::setOwner(void * o)
{
	owner = o;
}

unsigned char Body::getCollisionType()
{
	return collisionType;
}
void Body::setCollisionType(unsigned char byte)
{
	collisionType = byte;
}

bool Body::isCollisionType(unsigned char byte)
{
	return collisionType & byte;
}

unsigned char Body::getCollisionWith()
{
	return collisionWith;
}
void Body::setCollisionWith(unsigned char byte)
{
	collisionWith = byte;
}

void Body::addCollisionWith(unsigned char byte)
{
	collisionWith = collisionWith | byte;
}