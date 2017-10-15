#include "SoundManager.h"

sf::SoundBuffer& SoundManager::load(std::string dPath)
{
	Resource<sf::SoundBuffer> * res = new Resource<sf::SoundBuffer>();
	res->data.loadFromFile(dPath);
	res->path = dPath;

	data.push_front(res);

	return res->data;
}