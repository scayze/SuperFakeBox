#ifndef DISCGUN_H
#define DISCGUN_H

#include "Weapon.h"

class DiscGun : public Weapon
{
	private:

	public:
		DiscGun(Spielfeld * s);
		void shoot(bool right);

};


#endif
