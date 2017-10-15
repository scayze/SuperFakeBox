#include "MachieneGun.h"
#include <iostream>
#include "Bullet.h"


MachieneGun::MachieneGun(Spielfeld * s) : Weapon(s)
{
	//Change Body type to a Rect
	maxFireDelay = 4;
	name = "DRRRRRRRRRRRRR";
	knockback = 1.5;
	screenShakeAmount = 3;
	Resources::loadTexture(tex,"machinegun.png");
}

void MachieneGun::shoot(bool right)
{
	Resources::playSound("machinegun.wav");
	applyKnockback(right);
	Bullet * b = spielfeld->createObject<Bullet>(spr.getPosition().x,spr.getPosition().y);
	b->getBody()->setDecellMulti(1);
	sf::Vector2f velocity(15.f,0.f);
	velocity = Math::vectorRotate(velocity,Math::randomFloat(-0.35f,0.35f));
	if(right) b->getBody()->setVel(velocity);
	else b->getBody()->setVel(-velocity.x,velocity.y);


}
