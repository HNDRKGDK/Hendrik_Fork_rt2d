/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "player.h"

Player::Player() : Entity()
{
	this->addSprite("assets/square.tga");
	// this->sprite()->color = GREEN;
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
	//###############################################################
    // Movement
    // ###############################################################
    
    float moveSpeed = 500; 

    if (input()->getKeyDown(KeyCode::Space)) {
        bullet = new Bullet();
        bullet->position = this->position - Point2(0,50);
        this->addChild(bullet);
        this->parent()->addChild(bullet);
        bullets.push_back(bullet);
        std::cout << bullet->position.y << std::endl;
    }
    //Right
    if (input()->getKey(KeyCode::D)) 
    {
        this->position.x += moveSpeed * deltaTime;
        // cout << "Right";
    }
    //Left
    if (input()->getKey(KeyCode::A)) 
    {
        this->position.x -= moveSpeed * deltaTime;
        // cout << "Left";
    }
}