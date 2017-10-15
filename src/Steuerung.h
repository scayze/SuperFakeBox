#ifndef STEUERUNG_H
#define STEUERUNG_H

#include <SFML/Graphics.hpp>
#include "Spielfeld.h"
#include "GUI.h"

class Steuerung
{
	private:
		GUI rWindow;

		Spielfeld* spielfeld;

		double deltaTime;
		double time;

		sf::Clock clock;
		sf::Clock FPS;
		int fpscount;


	public:

		Steuerung();
		void run();
		void tick();
		void render();

};

#endif
