#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>


class Animation
{
	private:

		sf::Sprite * sprite;

		float speed;
		int maxframe;
		int frameDelay;


		bool repeat;
		bool paused;
		float time;
		int frame;


	public:
		int frameHeight;
		int frameWidth;


		Animation();
		Animation(sf::Sprite * spr, int mf, int fh, int fw, int fd);
		void tick();

		void update();
		void pause(bool p);
		void setMaxframe(int mf);
		void setFrame(int f);
		void setSpeed(float s);
		void setFrameDelay(int s);
		void setRepeat(bool b);
		void changeSprite(sf::Sprite * spr);
		bool isFinished();
		sf::Sprite * getSprite();
};

#endif