#ifndef SpriteEmitter_H
#define SpriteEmitter_H

#include "ParticleEmitter.h"


class SpriteEmitter : public ParticleEmitter
{
private:
	sf::Texture pTexture;
	sf::Sprite pSprite;

public:
	SpriteEmitter(sf::Vector2f pos, std::string s);
	void tick();
	void render(sf::RenderWindow * rW);
	sf::Texture * getTexture();
};

#endif