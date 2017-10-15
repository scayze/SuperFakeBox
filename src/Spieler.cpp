#include "Spieler.h"
#include "math.h"
#include <iostream>
#include "Weapons/Pistol.h"
#include "Weapons/MachieneGun.h"
#include "Weapons/Shotgun.h"
#include "Weapons/DualPistols.h"
#include "Weapons/MineDropper.h"
#include "Weapons/DiscGun.h"
#include "Weapons/RocketLauncher.h"
#include "ParticleSystem/SpriteEmitter.h"

//#include "spielfeld.h"

Spieler::Spieler(float x, float y) : Entity(x,y)
{
	state = 0;
	//type = t_spieler;
	speed = 9.f;
	accell = 2.f;
	//weapon = 0;
	//Laufen 13
	body->setSize(30.f,45.f);
	animation = Animation(&sprite,5,12,15,15);
	lookDirRight = true;
	animState = -1;
	//gravMulti = 
	sprite.setScale(sf::Vector2f(3,3));
}

void Spieler::init(Spielfeld * spiel)
{
	Entity::init(spiel);
	body->setCollisionWith(t_terrain | t_gegner);
	body->gravMulti = 1.f;
	body->setCollisionType(t_spieler);
	body->setDecellMulti(1.4);
	weapon = new DiscGun(spielfeld);
	sprite.setOrigin(sprite.getOrigin());
	
}

void Spieler::die()
{
	if(spielfeld->getFrameCount() < 5) return;
	state = 1;
	body->setVel(0,-15);

	body->setCollisionWith(t_noCollide);
	body->setCollisionType(t_noCollide);
	body->setDecellMulti(1.01f);
	body->gravMulti = 2.f;
	spielfeld->enableDeathScreen(true);
}

void Spieler::revive()
{
	state = 0;
	body->setVel(0,0);

	body->setCollisionType(t_spieler);
	body->setCollisionWith(t_terrain | t_gegner);
	body->gravMulti = 1.f;
	body->setDecellMulti(1.4);
	setWeapon(-1);
	sprite.setRotation(0);
}

void Spieler::tick()
{
	if(state == 1)
	{
		sprite.setRotation(Math::vectorGetRotation(body->getVel()) / Math::PI() * 180 + 90);
		return;
	}
	//update weapon pos

	weapon->tick();

    sf::Vector2f joyPos;
	joyPos.x = 0.f;
	joyPos.y = 0.f;
	
	//Jumping		
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(body->grounded)
        {
            joyPos.y = -18;
			SpriteEmitter * burst = new SpriteEmitter(sprite.getPosition() + sf::Vector2f(0,12),"cloud.png");
			burst->setMaxVelocity(0.25f);
			burst->setCount(1);
			burst->setSpreadAngle(0);
			burst->setDirection(Math::PI()*1.5);
			burst->setLifetime(35);
			burst->setScale(3.f);
			burst->setDensity(0.f);
			spielfeld->getParticleSystem()->addEmitter(burst);
        }
        if(body->getVel().y < -3)
        {
            body->gravMulti = 2.1f;
        }
        else body->gravMulti = 3.f;
    }
    else body->gravMulti = 4.f;

	//Moving
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		joyPos.x = -accell;
		lookDirRight = false;
		weapon->setDir(lookDirRight);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		joyPos.x = accell;
		lookDirRight = true;
		weapon->setDir(lookDirRight);
	}
	body->setVel(body->getVel() + sf::Vector2f(joyPos.x,joyPos.y)); 

	if(weapon->getOnePress())
	{
		if(Input::keyPressed(sf::Keyboard::X)) weapon->pressTrigger(lookDirRight);
	}
	else
	{
		if(Input::keyDown(sf::Keyboard::X)) weapon->pressTrigger(lookDirRight);
	}


	animation.tick();

	Entity::tick();

	float speeeeeed = fabs(body->getVel().x);
	if (speeeeeed > speed) 
	{
		if(body->getVel().x > 0) body->setVel(sf::Vector2f(speed, body->getVel().y));
		else body->setVel(sf::Vector2f(-speed, body->getVel().y));
		
	}

	body->grounded = false;

}

void Spieler::render(sf::RenderWindow * rW)
{

    if(lookDirRight != oldDirection)
    {
		if(!lookDirRight) sprite.setScale(sf::Vector2f(-3,3));
		else sprite.setScale(sf::Vector2f(3,3));
	    oldDirection = lookDirRight;
    }


	int newAnimState = 0;

	if(!body->grounded) newAnimState = 0;
	else if(fabs(body->getVel().x) < 2) newAnimState = 1;
    else newAnimState = 2;

	if(newAnimState != animState)
	{
		if(newAnimState == 0) {
			Resources::loadTexture(texture,"Player/jump.png");
			animation.frameWidth = 14;
			animation.frameHeight = 14;
			animation.setMaxframe(3);
			animation.setSpeed(3.f);
		}
		else if(newAnimState == 1) {
			Resources::loadTexture(texture,"Player/idle.png");
			animation.frameWidth = 12;
			animation.frameHeight = 15;
			animation.setMaxframe(5);
			animation.setSpeed(3.f);
		}
		else {
			Resources::loadTexture(texture,"Player/walk.png");
			animation.frameWidth = 12;
			animation.frameHeight = 15;
			animation.setMaxframe(5);
			animation.setSpeed(4.f);
		}
		animation.update();
		animState = newAnimState;
	}


    //animation.getSprite()->setPosition(body->getPos());


    rW->draw(*animation.getSprite());
	weapon->render(rW);
}

void Spieler::setWeapon(int w)
{
	delete weapon;
	if(w == -1) {
		weapon = new Pistol(spielfeld);
		return;
	}
	else if(w==0) {
		weapon = new Pistol(spielfeld);
	}
	else if(w==1) {
		weapon = new MachieneGun(spielfeld);
	}
	else if(w==2) {
		weapon = new Shotgun(spielfeld);
	}
	else if(w==3) {
		weapon = new DualPistols(spielfeld);
	}
	else if(w==4) {
		weapon = new MineDropper(spielfeld);
	}
	else if(w==5) {
		weapon = new DiscGun(spielfeld);
	}
	else if(w==6) {
		weapon = new RocketLauncher(spielfeld);
	}
	weapon->setDir(lookDirRight);
	spielfeld->showNotification(weapon->getName());
	//weapon = w;
}

void Spieler::collide(Entity * o)
{
	if(o->getBody()->isCollisionType(t_gegner) || o->getBody()->isCollisionType(t_fire))
	{
		die();
	}
	else if(o->getBody()->isCollisionType(t_crate))
	{
		spielfeld->spawnCrate();
		o->flag_destroy = true;
		setWeapon(rand() % 7);

		o->getBody()->setCollisionType(0);
		o->getBody()->setCollisionWith(0);
	}
}