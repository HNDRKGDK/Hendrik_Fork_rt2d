/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "player.h"
#include "bullet.h"
#include "collider.h"
#include "shape.h"

Player::Player() : Entity()
{
	this->addSprite("assets/square.tga");

	// player collidor circle
	playercircle = new Shape();
	// circle1->position = Point2(400, 200);
	Line pc1;
	pc1.createCircle(64, 18);
	playercircle->addLine(&pc1);
	this->addChild(playercircle);
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

    // create player circle
    Circle playercircle = Circle(this->position.x, this->position.y, 64);

    if (input()->getKeyDown(KeyCode::Space)) {
        playerbullet = new Bullet(-400);
        playerbullet->position = this->position - Point2(0,50);
        this->addChild(playerbullet);

        this->parent()->addChild(playerbullet);
        playerbullets.push_back(playerbullet);
        std::cout << playerbullet->position.y << std::endl;
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