#include "Input.h"
#include <iostream>

static bool keyStates[sf::Keyboard::KeyCount] = { false };
static bool buttonStates[sf::Mouse::ButtonCount] = { false, false, false, false, false };
static sf::RenderWindow * window;

void Input::init(sf::RenderWindow * w)
{
	window = w;
	for (int i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		keyStates[i] = false;
	}

	for (int i = 0; i < sf::Mouse::ButtonCount; i++)
	{
		buttonStates[i] = false;
	}
}

void Input::updateInputStates()
{
	for (int i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		keyStates[i] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key(i));
	}

	for (int i = 0; i < sf::Mouse::ButtonCount; i++)
	{
		buttonStates[i] = sf::Mouse::isButtonPressed(sf::Mouse::Button(i));
	}
}

//Keyboard
bool Input::keyPressed(sf::Keyboard::Key k)
{
	return (sf::Keyboard::isKeyPressed(k) && !keyStates[k]);
}

bool Input::keyReleased(sf::Keyboard::Key k)
{
	return (!sf::Keyboard::isKeyPressed(k) && keyStates[k]);
}

bool Input::keyDown(sf::Keyboard::Key k)
{
	return sf::Keyboard::isKeyPressed(k);
}

//Mouse
bool Input::mousePressed(sf::Mouse::Button b)
{
	return (sf::Mouse::isButtonPressed(b) && !buttonStates[b]);
}

bool Input::mouseReleased(sf::Mouse::Button b)
{
	return (!sf::Mouse::isButtonPressed(b) && buttonStates[b]);
}

bool Input::mouseDown(sf::Mouse::Button b)
{
	return sf::Mouse::isButtonPressed(b);
}

sf::Vector2f Input::getMouseCoordsPosition()
{
	return window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}
