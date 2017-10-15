#ifndef MACHGUN_H
#define MACHGUN_H

#include "Weapon.h"

class MachieneGun : public Weapon
{
	private:

	public:
		MachieneGun(Spielfeld * s);
		void shoot(bool right);

};


#endif
