#include "FontManager.h"

sf::Font& FontManager::load(std::string dPath)
{
	Resource<sf::Font> * res = new Resource<sf::Font>();
	res->data.loadFromFile(dPath);
	res->path = dPath;

	data.push_front(res);

	return res->data;
}