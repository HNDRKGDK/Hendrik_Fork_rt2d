/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "myentity.h"

MyEntity::MyEntity() : Entity()
{
	this->addSprite("assets/square1.tga");
	this->sprite()->color = GREEN;
}

MyEntity::~MyEntity()
{

}

void MyEntity::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	// ###############################################################
	// this->rotation.z += PI * deltaTime; // 90 deg/sec
	// if (this->rotation.z > TWO_PI) {
	// 	this->rotation.z -= TWO_PI;
	// }
}
