/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "enemyblock.h"

EnemyBlock::EnemyBlock() : Entity()
{
	this->addSprite("assets/square1.tga");
	// this->sprite()->color = GREEN;
}

EnemyBlock::~EnemyBlock()
{

}

void EnemyBlock::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	// ###############################################################
	// this->rotation.z += PI * deltaTime; // 90 deg/sec
	// if (this->rotation.z > TWO_PI) {
	// 	this->rotation.z -= TWO_PI;
	// }
	

}
