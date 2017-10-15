#ifndef Resources_H
#define Resources_H

#include "Managers/TextureManager.h"
#include "Managers/FontManager.h"
#include "Managers/SoundManager.h"

class Resources
{
private:



public:

	static const sf::Image& getTexture(std::string path);
	static void loadTexture(sf::Texture& tex, std::string path);
	static const sf::Font& getFont(std::string path);
	static const sf::SoundBuffer& getSound(std::string path);
	static void playSound(std::string path);
};

#endif
