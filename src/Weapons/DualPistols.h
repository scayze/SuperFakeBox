#ifndef DUALPISTOL_H
#define DUALPISTOL_H

#include "Weapon.h"

class DualPistols : public Weapon
{
	private:

	public:
		DualPistols(Spielfeld * s);
		void render(sf::RenderWindow * rW);
		void shoot(bool right);

};


#endif
