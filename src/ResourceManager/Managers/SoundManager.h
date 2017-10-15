#ifndef SoundManager_h
#define SoundManager_h

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "../Manager.h"

class SoundManager : public ResourceManager<sf::SoundBuffer>
{
private:

	sf::SoundBuffer& load(std::string dPath);

public:
};

#endif