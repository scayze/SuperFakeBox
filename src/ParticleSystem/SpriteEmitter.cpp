#include "SpriteEmitter.h"

SpriteEmitter::SpriteEmitter(sf::Vector2f pos, std::string s) : ParticleEmitter(pos)
{
	Resources::loadTexture(pTexture,s);
	pSprite.setTexture(pTexture);
}

void SpriteEmitter::tick()
{
	ParticleEmitter::tick();
}

void SpriteEmitter::render(sf::RenderWindow * rW)
{
	for (unsigned int i = 0; i < particles.size(); i++)
	{
		//Apply alpha if enabled
		if (fadeOut) pSprite.setColor(sf::Color(pSprite.getColor().r, pSprite.getColor().g, pSprite.getColor().b, (float)particles[i].time / (float)lifetime * 255));
		//Apply scale and position to particle
		pSprite.setScale(particles[i].size, particles[i].size);
		//pSprite.setPosition(particles[i].position);

		if(localPos) pSprite.setPosition(particles[i].position + position);
		else pSprite.setPosition(particles[i].position);
		//render
		rW->draw(pSprite);
	}
}


sf::Texture * SpriteEmitter::getTexture()
{
	return &pTexture;
}