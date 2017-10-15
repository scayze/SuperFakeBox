#ifndef WEAPON_H
#define WEAPON_H

#include "../Spielfeld.h"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "../ResourceManager/Resources.h"

class Weapon
{
	protected:

		float knockback;
		int maxFireDelay;
		int fireDelay;
		std::string name;

		sf::Texture tex;
		sf::Sprite spr;

		Spielfeld * spielfeld;
		bool right;

		bool onePress;
		int screenShakeAmount;

	public:

		Weapon(Spielfeld * spiel);
		virtual void render(sf::RenderWindow * rW);
		void tick();
		void setDir(bool right);
		void pressTrigger(bool right);
		void applyKnockback(bool right);
		virtual void shoot(bool right) = 0;
		void setPos(sf::Vector2f v) { spr.setPosition(v); };
		std::string getName() { return name; };
		bool getOnePress() { return onePress; };
		void setKnockback(float kb);

};


#endif
