#ifndef PISTOL_H
#define PISTOL_H

#include "Weapon.h"

class Pistol : public Weapon
{
	private:

	public:
		Pistol(Spielfeld * s);
		void shoot(bool right);

};


#endif
