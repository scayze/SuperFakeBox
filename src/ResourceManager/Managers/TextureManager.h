#ifndef TextureManager_h
#define TextureManager_h

#include <SFML/Graphics.hpp>
#include "../Manager.h"

class TextureManager : public ResourceManager<sf::Image>
{
private:

	sf::Image& load(std::string dPath);

public:
};





#endif