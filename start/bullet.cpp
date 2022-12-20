/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "bullet.h"
#include "player.h" 
#include "collider.h"

Bullet::Bullet(int s) : Entity()
{
	bulletSpeed = s;
	this->addSprite("assets/bullet.tga");
	// this->sprite()->color = RED;
	// ddCircle(this->position.x, this->position.y, 32,WHITE);

		// Circle1
	bulletcircle = new Shape();
	// circle1->position = Point2(400, 200);
	Line bc1;
	bc1.createCircle(64, 18);
	bulletcircle->addLine(&bc1);
	this->addChild(bulletcircle);

		
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	Circle circ1 = Circle(this->position.x, this->position.y, 64);
	this->position.y += bulletSpeed * deltaTime;
}
