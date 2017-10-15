#include "ShapeEmitter.h"

template<class T>
ShapeEmitter<T>::ShapeEmitter(sf::Vector2f pos) : ParticleEmitter(pos)
{

}

template<class T>
ShapeEmitter<T>::~ShapeEmitter()
{
	delete shape;
}

template<class T>
void ShapeEmitter<T>::tick()
{
	ParticleEmitter::tick();
}

template<class T>
void ShapeEmitter<T>::render(sf::RenderWindow * rW)
{
	for (unsigned int i = 0; i < particles.size(); i++)
	{
		if (fadeOut) shape->setFillColor(sf::Color(shape->getFillColor().r, shape->getFillColor().g, shape->getFillColor().b, (float)particles[i].time / (float)lifetime * 255));
		
		if(localPos) shape->setPosition(particles[i].position + position);
		else shape->setPosition(particles[i].position);

		//shape->setPosition(particles[i].position);
		shape->setScale(particles[i].size, particles[i].size);
		rW->draw(*shape);
	}
}

template<class T>
void ShapeEmitter<T>::setShape(T * s)
{
	shape = s;
}

template class ShapeEmitter<sf::RectangleShape>;
template class ShapeEmitter<sf::CircleShape>;
template class ShapeEmitter<sf::ConvexShape>;