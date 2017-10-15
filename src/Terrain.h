#ifndef TERRAIN_H
#define TERRAIN_H

#include "Entity.h"

class Terrain : public Entity
{
	private:
		bool wall;
		sf::RenderTexture rTex;
	public:
		Terrain(float x,float y);
		void init(Spielfeld * spiel);

		void render(sf::RenderWindow * rW);
		void tick();

		void setSize(int w, int h);
		void setSize(sf::Vector2f dim);

		void setWall(bool y);
		bool isWall();



};


#endif
