#ifndef Input_h
#define Input_h


#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Input
{
	private:

	public:


		static void init(sf::RenderWindow * w);
		static void updateInputStates();

		static bool mousePressed(sf::Mouse::Button b);
		static bool mouseReleased(sf::Mouse::Button b);
		static bool mouseDown(sf::Mouse::Button b);
		static sf::Vector2f getMouseCoordsPosition();

		static bool keyPressed(sf::Keyboard::Key k);
		static bool keyReleased(sf::Keyboard::Key k);
		static bool keyDown(sf::Keyboard::Key k);

};


#endif