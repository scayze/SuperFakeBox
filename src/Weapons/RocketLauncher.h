#ifndef ROCKET_LAUNCHER_H
#define ROCKET_LAUNCHER_H

#include "Weapon.h"

class RocketLauncher : public Weapon
{
	private:

	public:
		RocketLauncher(Spielfeld * s);
		void shoot(bool right);

};


#endif
