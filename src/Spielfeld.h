#ifndef SPIELFELD_H
#define SPIELFELD_H


#include <SFML/Graphics.hpp>
#include "Physics/PhysicsSystem.h"
#include "ParticleSystem/ParticleSystem.h"

class Entity;
class Spieler;


class Spielfeld
{
	private:

		int frameCount;

		bool deathScreen;

		Spieler * player;
		sf::Vector2f screenOffset;
		std::vector<int> screenShakes;

		PhysicsSystem pSystem;
		ParticleSystem partSystem;

		std::vector<Entity*> objects;

		sf::Texture backgroundTex;
		sf::Sprite background;

		sf::RenderWindow* rWindow;

		sf::Vector2f spawnPos;
		int spawnCounter;
		int spawnSpeed;
		int score;

		sf::Text scoreText;
		sf::Text notification;
		sf::Text restartMessage;

	public:
		Spielfeld(sf::RenderWindow* window);

		void tick();
		void render(float delta);

		void enableDeathScreen(bool b);
		void spawnCrate();
		void spawnEnemy();
		void showNotification(std::string str);
		void screenShake(int intensity);
		void restart();

		Spieler * getPlayer();
		PhysicsSystem * getPhysicsSystem();
		ParticleSystem * getParticleSystem();
		sf::RenderWindow * getRenderWindow();
		std::vector<Entity*> * getObjects();
		int getFrameCount();
		sf::Vector2f getScreenOffset();

		template<typename T>
		T* createObject(float x, float y)
		{
			T* obj = new T(x,y);
			obj->init(this);
			pSystem.addBody(obj->getBody());
			objects.push_back(obj);
			return obj;
		};

};

#endif
