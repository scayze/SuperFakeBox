#include "TextureManager.h"

sf::Image& TextureManager::load(std::string dPath)
{
	Resource<sf::Image> * res = new Resource<sf::Image>();
	res->data.loadFromFile(dPath);
	res->path = dPath;

	data.push_front(res);

	return res->data;
}