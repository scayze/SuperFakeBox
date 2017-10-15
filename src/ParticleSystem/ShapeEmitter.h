#ifndef ShapeEmitter_H
#define ShapeEmitter_H

#include "ParticleEmitter.h"

#include <SFML/Graphics/RectangleShape.hpp>

template <class T>
class ShapeEmitter : public ParticleEmitter
{
private:
	T * shape;

public:
	ShapeEmitter(sf::Vector2f pos);
	~ShapeEmitter();
	void tick();
	void render(sf::RenderWindow * rW);
	void setShape(T * s);
};

typedef ShapeEmitter<sf::RectangleShape>	RectangleEmitter;
typedef ShapeEmitter<sf::CircleShape>		CircleEmitter;
typedef ShapeEmitter<sf::ConvexShape>		ConvexEmitter;


#endif
