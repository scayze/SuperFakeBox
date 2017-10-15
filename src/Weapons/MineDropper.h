#ifndef MINEDROP_H
#define MINEDROP_H

#include "Weapon.h"

class MineDropper : public Weapon
{
	private:

	public:
		MineDropper(Spielfeld * s);
		void shoot(bool right);

};


#endif
