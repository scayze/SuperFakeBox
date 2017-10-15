#ifndef Entity_H
#define Entity_H

#include <SFML/Graphics.hpp>
#include "Spielfeld.h"
#include "Physics/Body.h"
#include "math.h"
#include "ResourceManager/Resources.h"
#include "Input.h"
#include "Animation.h"


enum type : unsigned char
{
	t_noCollide =	0,
	t_terrain =		1,
	t_spieler =		2,
	t_bullet =		4,
	t_gegner =		8,
	t_fire =		16,
	t_crate =		32
};

class Entity
{
	protected:


		Spielfeld * spielfeld;

		sf::Texture texture;
		sf::Sprite sprite;

		Body * body;


	public:
		Entity(float x, float y);
		virtual ~Entity();
		virtual void init(Spielfeld * spiel);
		virtual void tick();

		virtual void render(sf::RenderWindow * rW);
		virtual void collide(Entity * object);

		sf::Sprite& getSprite();
		Body * getBody();

		bool flag_destroy;
		bool flag_visible;
};

#endif
