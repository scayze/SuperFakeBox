#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

class GUI : public sf::RenderWindow
{
private:
	sf::View view;
public:
	GUI()
	{
		view.reset(sf::FloatRect(0,0,1200,800));
		setView(view);
	};
	void applyScreenShake(sf::Vector2f vec)
	{
		view.setCenter(vec + (sf::Vector2f)getSize() / 2.f);
		setView(view);
	};
};

#endif
