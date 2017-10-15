#ifndef SCHROTZE_H
#define SCHROTZE_H

#include "Weapon.h"

class Shotgun : public Weapon
{
	private:

	public:
		Shotgun(Spielfeld * s);
		void shoot(bool right);

};


#endif
