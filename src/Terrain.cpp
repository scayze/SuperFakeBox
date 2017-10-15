#include "Terrain.h"
#include <iostream>

Terrain::Terrain(float x, float y) : Entity(x,y)
{
	//Change Body type to a Rect

	body->setCollisionType(t_terrain);
	body->gravMulti = 0.f;
	wall = false;
	//Non movable
	body->isStatic = true;
	//Resources::loadTexture(texture,"terrain300x50.png");
	//flag_visible = true;


}

void Terrain::render(sf:: RenderWindow * rW)
{
	//Entity::render(rW);
	//sf::Sprite sp;
	//sp.setTexture(rTex.getTexture());
	//sp.setPosition(body->getPos());
	//sp.setOrigin(sp.getLocalBounds().width/2,sp.getLocalBounds().height/2);
	////sp.setScale(3,3);
	//sprite.setTexture(rTex.getTexture());
	sf::Sprite spr;
	spr.setTexture(rTex.getTexture());
	spr.setPosition(body->getPos());
	spr.setScale(3,3);
	spr.setOrigin(spr.getLocalBounds().width/2,spr.getLocalBounds().height/2);
	rW->draw(spr);
}

void Terrain::setSize(int w,int h)
{
	body->setSize(w,h);
	if(wall) return;
	//Create the empty render Texture
	//rTex.create( (w-(w%3))/3, (h-(h%3))/3 );
	rTex.create( w/3, h/3 );
	rTex.clear();

	//Load the necessary textures
	sf::Texture bot_corner;
	Resources::loadTexture(bot_corner,"drawer/bot_corner.png");
	sf::Sprite spr_bot_corner;
	spr_bot_corner.setTexture(bot_corner);

	sf::Texture top_corner;
	Resources::loadTexture(top_corner,"drawer/top_corner.png");
	sf::Sprite spr_top_corner;
	spr_top_corner.setTexture(top_corner);

	sf::Texture knob;
	Resources::loadTexture(knob,"drawer/knob2.png");
	sf::Sprite spr_knob;
	spr_knob.setTexture(knob);

	sf::Texture side;
	Resources::loadTexture(side,"drawer/side.png");
	sf::Sprite spr_side;
	spr_side.setTexture(side);

	sf::Texture top;
	Resources::loadTexture(top,"drawer/top.png");
	sf::Sprite spr_top;
	spr_top.setTexture(top);

	sf::Texture bot;
	Resources::loadTexture(bot,"drawer/bot.png");
	sf::Sprite spr_bot;
	spr_bot.setTexture(bot);

	sf::Texture bg;
	Resources::loadTexture(bg,"drawer/bg.png");
	sf::Sprite spr_bg;
	spr_bg.setTexture(bg);

	//Draw BG
	spr_bg.setPosition(0,0);
	spr_bg.setScale((sf::Vector2f)rTex.getSize());
	rTex.draw(spr_bg);

	//top
	spr_top.setPosition(0,0);
	spr_top.setScale(rTex.getSize().x,1);
	rTex.draw(spr_top);

	//bot
	spr_bot.setPosition(0,rTex.getSize().y-3);
	spr_bot.setScale(rTex.getSize().x,1);
	rTex.draw(spr_bot);

	//Left Border
	spr_side.setPosition(0,0);
	spr_side.setScale(1,rTex.getSize().y);
	rTex.draw(spr_side);

	spr_top_corner.setPosition(0,0);
	spr_top_corner.setScale(1,1);
	rTex.draw(spr_top_corner);

	spr_bot_corner.setPosition(0,rTex.getSize().y-3);
	spr_bot_corner.setScale(1,1);
	rTex.draw(spr_bot_corner);

	//Right Border
	spr_side.setPosition(rTex.getSize().x,0);
	spr_side.setScale(-1,rTex.getSize().y);
	rTex.draw(spr_side);

	spr_top_corner.setPosition(rTex.getSize().x,0);
	spr_top_corner.setScale(-1,1);
	rTex.draw(spr_top_corner);

	spr_bot_corner.setPosition(rTex.getSize().x,rTex.getSize().y-3);
	spr_bot_corner.setScale(-1,1);
	rTex.draw(spr_bot_corner);

	//Knob
	spr_knob.setPosition((sf::Vector2f)rTex.getSize()/2.f);
	spr_knob.setOrigin(6,5.5);
	rTex.draw(spr_knob);

	rTex.display();
	sprite.setTexture(rTex.getTexture());
	sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
	sprite.setScale(3,3);

	
	std::cout << "Terrain-size set & Drawn to RenderTexture" << std::endl;
}

void Terrain::setSize(sf::Vector2f dim)
{
	setSize(dim.x,dim.y);
}


void Terrain::tick()
{
	Entity::tick();
}

void Terrain::init(Spielfeld * spiel)
{
	Entity::init(spiel);
	
}

void Terrain::setWall(bool y)
{
	wall = y;	
}

bool Terrain::isWall()
{
	return wall;
}

