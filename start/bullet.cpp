/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "bullet.h"

Bullet::Bullet() : Entity()
{
	this->addSprite("assets/bullet.tga");
	// this->sprite()->color = RED;

	bulletSpeed = 500;
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	this->position.y -= bulletSpeed * deltaTime;
}
