#include "Steuerung.h"
#include <iostream>
#include "Input.h"

Steuerung::Steuerung()
{
	deltaTime = 1.0 / 60.0;
	time = 0;

	rWindow.create(sf::VideoMode(1200,800),"Super Fake Box");
	//rWindow.setVerticalSyncEnabled(true);

	spielfeld = new Spielfeld(&rWindow);
	Input::init(&rWindow);

}

void Steuerung::run()
{

	while(rWindow.isOpen())
	{
		sf::Event event;

		while(rWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				rWindow.close();
			}
		}

		//Semi Fixed Timestep
		time += clock.restart().asSeconds();
		while(time >= deltaTime)
		{
			tick();
			time-=deltaTime;
			Input::updateInputStates();
		}
		render();
		fpscount++;
		

		if(FPS.getElapsedTime().asSeconds()>1)
		{
			FPS.restart();
			std::cout << fpscount << std::endl;
			fpscount=0;
		}
	}
}

void Steuerung::tick()
{
	spielfeld->tick();
}

void Steuerung::render()
{
	rWindow.applyScreenShake(spielfeld->getScreenOffset());

	rWindow.clear(sf::Color::Cyan);

	spielfeld->render(time / deltaTime);

	rWindow.display();
}