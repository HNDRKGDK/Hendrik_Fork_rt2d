/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "enemyblock.h"

EnemyBlock::EnemyBlock() : Entity()
{
	this->addSprite("assets/square1.tga");
	enemybullet->bulletSpeed * -1;
	// std::cout << bullet->bulletSpeed << std::endl;
		//enemycircle circle
	enemycircle = new Shape();
	// circle1->position = Point2(400, 200);
	Line ec1;
	ec1.createCircle(64, 18);
	enemycircle->addLine(&ec1);
	this->addChild(enemycircle);
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

   	// create enemy circle
	Circle enemycircle = Circle(this->position.x, this->position.y, 64);

	this->rotation.z += PI * deltaTime; // 90 deg/sec
	if (this->rotation.z > TWO_PI) {
		this->rotation.z -= TWO_PI;
	}

	    if (input()->getKeyDown(KeyCode::B)) {
        enemybullet = new Bullet(400);
        enemybullet->position = this->position - Point2(0,50);
        this->addChild(enemybullet);
        this->parent()->addChild(enemybullet);
        enemybullets.push_back(enemybullet);
        std::cout << enemybullet->position.y << std::endl;
    }
	
}