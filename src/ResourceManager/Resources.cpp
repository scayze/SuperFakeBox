#include "Resources.h"
#include "iostream"

TextureManager tManager;
FontManager fManager;
SoundManager sManager;

std::vector<sf::Sound*> sounds;

void Resources::loadTexture(sf::Texture& tex, std::string path)
{
	tex.loadFromImage(tManager.get("Resources/Graphics/" + path));
}

const sf::Image& Resources::getTexture(std::string path)
{
	return tManager.get("Resources/Graphics/" + path);
}

const sf::Font& Resources::getFont(std::string path)
{
	return fManager.get("Resources/fonts/" + path);
}

const sf::SoundBuffer& Resources::getSound(std::string path)
{
	return sManager.get("Resources/Sounds/" + path);
}

void Resources::playSound(std::string path)
{
	sf::Sound * s = new sf::Sound(getSound(path));
	s->play();
	sounds.push_back(s);

	for(unsigned int i = 0; i<sounds.size();i++)
	{
		if(sounds[i]->getStatus() == sf::Sound::Stopped || sounds[i]->getStatus() == sf::Sound::Paused)
		{
			delete sounds[i];
			sounds.erase(sounds.begin() + i);
		}
	}

}