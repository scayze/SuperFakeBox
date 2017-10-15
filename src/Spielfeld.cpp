#include <iostream>

#include "ParticleSystem/ParticleSystem.h"

#include "Spielfeld.h"

#include "Terrain.h"
#include "Fire.h"
#include "Crate.h"
#include "Explosion.h"

#include "Spieler.h"
#include "Enemies/Fork.h"
#include "Enemies/MassiveFork.h"
#include "Enemies/Fly.h"


#include "Weapons/Bullet.h"
#include "Weapons/Mine.h"
#include "Weapons/Disc.h"
#include "Weapons/Rocket.h"


Spielfeld::Spielfeld(sf::RenderWindow *window)
{
	Resources::playSound("newtry3.wav");
	//set players spawn position
	spawnPos = sf::Vector2f(window->getSize().x/2,40.f);
	//initialize window
	rWindow = window;
	//Initialize some varialbes
	deathScreen = false;

	//Load font and create the score text
	scoreText.setFont(Resources::getFont("Pixeled.ttf"));
	scoreText.setPosition(window->getSize().x/2,100);

	//Load font and create the Notification text
	notification.setFont(Resources::getFont("Pixeled.ttf"));
	notification.setPosition(window->getSize().x/2,175);

	//Load font and create the Notification text
	restartMessage.setFont(Resources::getFont("Pixeled.ttf"));
	restartMessage.setPosition(window->getSize().x/2,window->getSize().y / 5 * 3);
	restartMessage.setString("PRESS 'ENTER' TO RESTART.");
	restartMessage.setOrigin(restartMessage.getCharacterSize() * restartMessage.getString().getSize() / 2, restartMessage.getCharacterSize());

	//Objects
	player = createObject<Spieler>(0, 0);
	Fire * fire = createObject<Fire>(window->getSize().x/2,window->getSize().y - 15);

	///Terrain
	//block top
	Terrain * top = createObject<Terrain>(600.f, 210.f);
	top->setSize(600.f,50);

	//block bot
	Terrain * bot = createObject<Terrain>(600.f, 560.f);
	bot->setSize(600.f,50);

	//block top left
	Terrain * tl = createObject<Terrain>(150.f, 380.f);
	tl->setSize(300.f,50);

	//block top right
	Terrain * tr = createObject<Terrain>(1050.f, 380.f);
	tr->setSize(300.f,50);

	//block bot left left
	Terrain * blt = createObject<Terrain>(180, 750.f);
	blt->setSize(360,100);

	//block bot right right
	Terrain * brt = createObject<Terrain>(1020.f, 750.f);
	brt->setSize(360,100);

	//block bot left right
	Terrain * bl = createObject<Terrain>(454, 770.f);
	bl->setSize(190.f,60);

	//block bot right left
	Terrain * br = createObject<Terrain>(746, 770.f);
	br->setSize(190.f,60);

	//Borders around the level
	Terrain * p1_p2 = createObject<Terrain>(window->getSize().x/2.f, -20.f);
	Terrain * p2_p3 = createObject<Terrain>(window->getSize().x+ 20.f,window->getSize().y/2.f);
	Terrain * p3_p4 = createObject<Terrain>(window->getSize().x/2.f,window->getSize().y+20.f);
	Terrain * p4_p1 = createObject<Terrain>(-20.f,window->getSize().y/2);

	p1_p2->setWall(true);
	p2_p3->setWall(true);
	p3_p4->setWall(true);
	p4_p1->setWall(true);

	p1_p2->setSize(window->getSize().x, 40.f);
	p2_p3->setSize(40.f, window->getSize().y);
	p3_p4->setSize(window->getSize().x,40.f);
	p4_p1->setSize(40.f,window->getSize().y);
	


	//Background
	Resources::loadTexture(backgroundTex,"kitchen.jpg");
	background.setTexture(backgroundTex);
	background.setScale(1.5,1.5);
	//backgound.clear(sf::Color(25, 25, 25));

	//(Re)start the game.
	restart();
}

void Spielfeld::tick()
{
	//Counter stuff
	spawnCounter++;
	frameCount++;
	background.setPosition(-(((player->getSprite().getPosition().x)-600)/10)-60,0);
	//Spawn enemy when time arrives.
	if (spawnCounter >= spawnSpeed) spawnEnemy();

	//walk though all entities and delete them if marked
	for(unsigned int i=0; i < objects.size(); i++)
	{
		if(objects[i]->flag_destroy == true)
		{
			delete objects[i];
			objects.erase(objects.begin()+i);
		}
	}

	//Update the remaining objets
	for(unsigned int i=0; i < objects.size(); i++)
	{
		objects[i]->tick();
	}

	//restart the game when were in the deathscreen and return is pressed
	if (deathScreen && Input::keyPressed(sf::Keyboard::Return)) restart();

	//Update physics system
	pSystem.tick();
	//Update particle system
	partSystem.tick();

	//Decrease notification alpha until its basicly 0
	if (notification.getColor().a >= 2) notification.setColor(sf::Color(255,255,255,notification.getColor().a-2));

}

void Spielfeld::render(float delta)
{
	//Render the background
	rWindow->draw(background);

	//Update screenshake if the timer is larger zero -> when screenshake is still in effect
	int intensity = 0;
	for(unsigned int i=0;i< screenShakes.size();i++)
	{
		intensity += screenShakes[i];
		--screenShakes[i];
		if(screenShakes[i] == 0) screenShakes.erase(screenShakes.begin() + i);
	}

	if(intensity > 0) {
		screenOffset.x = (float)intensity / 2.6f * sin((float)frameCount / 2.5f);
		screenOffset.y = (float)intensity / 2.6f * cos((float)frameCount / 2.5f);
	}
	else
	{
		//If not reset it to zero.
		screenOffset.x = 0.f;
		screenOffset.y = 0.f;
	}

	//Walk though all objects and check if they are visible. then render them
	for(unsigned int i=0; i < objects.size(); i++)
	{
		if(objects[i]->flag_visible)
		{
			//Update position of the sprite, interpolation with the bodys velocity for smoother visuals on higher FPS
			objects[i]->getSprite().setPosition(objects[i]->getBody()->getPos() + objects[i]->getBody()->getVel() * delta);
			objects[i]->render(rWindow);
		}
	}

	//Draw all texts on the screen
	rWindow->draw(notification);
	rWindow->draw(scoreText);
	if(deathScreen) rWindow->draw(restartMessage);
	
	//render the particle system
	partSystem.render(rWindow);
	//render the Physic bodies if this debug option is enabled
	pSystem.debugRender(rWindow);
}

void Spielfeld::spawnEnemy()
{
	int random = Math::randomInt(0,10);
	Gegner * g;
	if(random<=5) g = createObject<Fork>(spawnPos.x,spawnPos.y);
	else if(random<=9) g = createObject<MassiveFork>(spawnPos.x,spawnPos.y);
	else g = createObject<Fly>(spawnPos.x,spawnPos.y);
		 
	spawnSpeed = Math::randomInt(20,120);
	spawnCounter = 0;	
}

void Spielfeld::spawnCrate()
{
	std::vector<Terrain*> terrain;
	for(unsigned int i=0; i < objects.size(); i++)
	{
		if(objects[i]->getBody()->isCollisionType(t_terrain))
		{
			if(!static_cast<Terrain*>(objects[i])->isWall()) {
				terrain.push_back(static_cast<Terrain*>(objects[i]));
			}
		}
	}
	int r = rand() % terrain.size();
	sf::Vector2f size = terrain[r]->getBody()->getSize();
	sf::Vector2f pos = terrain[r]->getBody()->getPos();
	float crate_spawn_x = pos.x - size.x/2 + rand() % (int)size.x;
	float crate_spawn_y = pos.y - size.y/2 - 8;
	createObject<Crate>(crate_spawn_x,crate_spawn_y);

	score++;
	scoreText.setString(std::to_string(score));
	scoreText.setOrigin(scoreText.getCharacterSize() * scoreText.getString().getSize() / 2, scoreText.getCharacterSize());
}

void Spielfeld::showNotification(std::string str)
{
	notification.setColor(sf::Color(notification.getColor().r,notification.getColor().g,notification.getColor().b,255));
	notification.setString(str);
	notification.setOrigin(notification.getCharacterSize() * notification.getString().getSize() / 2, notification.getCharacterSize());
}

void Spielfeld::restart()
{
	for(unsigned i=0;i< objects.size(); i++)
	{
		if(objects[i]->getBody()->isCollisionType(t_gegner) || objects[i]->getBody()->isCollisionType(t_crate) || objects[i]->getBody()->isCollisionType(t_bullet) || objects[i]->getBody()->isCollisionType(t_crate))
		{
			objects[i]->flag_destroy = true;
		}
	}

	player->getBody()->setPos(600.f,450.f);
	player->revive();
	score = -1;
	frameCount = 0;
	scoreText.setPosition(rWindow->getSize().x/2,100);
	enableDeathScreen(false);

	spawnCounter = 0;
	spawnSpeed = 100;

	spawnCrate();
}

void Spielfeld::enableDeathScreen(bool b)
{
	deathScreen = b;
	if(b)
	{
		scoreText.setPosition(rWindow->getSize().x/2,rWindow->getSize().y / 2);
		scoreText.setScale(5,5);
		spawnCounter = 100000;
	}
	else 
	{
		scoreText.setPosition(rWindow->getSize().x/2,100);
		scoreText.setScale(1,1);
		spawnCounter = spawnSpeed;
	}
}

Spieler * Spielfeld::getPlayer()
{
	return player;
}

PhysicsSystem * Spielfeld::getPhysicsSystem()
{
	return &pSystem;
}

ParticleSystem * Spielfeld::getParticleSystem()
{
	return &partSystem;
}

sf::RenderWindow * Spielfeld::getRenderWindow()
{
	return rWindow;
}

void Spielfeld::screenShake(int i)
{
	screenShakes.push_back(i);
}

sf::Vector2f Spielfeld::getScreenOffset()
{
	return screenOffset;
}

std::vector<Entity*> * Spielfeld::getObjects()
{
	return &objects;
}

int Spielfeld::getFrameCount()
{
	return frameCount;
}