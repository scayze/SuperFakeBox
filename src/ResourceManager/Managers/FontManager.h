#ifndef FontManager_H
#define FontManager_H

#include <SFML/Graphics.hpp>
#include "../Manager.h"

class FontManager : public ResourceManager<sf::Font>
{
private:

	sf::Font& load(std::string dPath);

public:
};





#endif