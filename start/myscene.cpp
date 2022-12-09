/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */
#include <iostream>
#include <vector>
#include <list>

#include <fstream>
#include <sstream>
#include "myscene.h"
#include "enemyBlock.h"

using namespace std;

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	// create single instance player.
	player = new Player();
	player->position = Point2(SWIDTH/2, SHEIGHT/1.1);

	enemy = new EnemyBlock();
	enemy->position = Point2(SWIDTH/2, SHEIGHT/2);

	// create the scene 'tree'
	// add player to this Scene as a child.
	this->addChild(player);
	this->addChild(enemy);

}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(enemy);
	this->removeChild(player);
	//this->removeChild(bullet);
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	// if (input()->getKeyDown(KeyCode::Space)) {
	// 	player->scale = Point(0.5f, 0.5f);
	// }
	// if (input()->getKeyUp(KeyCode::Space)) {
	// 	player->scale = Point(1.0f, 1.0f);
	// }

	for (int i = player->bullets.size() - 1; i >= 0; i--) {
        if (player->bullets[i]->position.x > SWIDTH || player->bullets[i]->position.x < 0 || player->bullets[i]->position.y < 0 || player->bullets[i]->position.y > SHEIGHT)
        {
            this->removeChild(player->bullets[i]);
            delete player->bullets[i];
            player->bullets.erase(player->bullets.begin() + i);
            std::cout << "bullet deleted" << std::endl;
        }
    }

	//###############################################################
    // Movement
    // ###############################################################
	
	// if (input()->getKeyDown(KeyCode::Space)) {

	// 	std::vector<Bullet*> bullets;
	// 	Bullet* b = new Bullet(); // create a new Bullet on the heap
	// 	bullets.push_back(b); // keep a pointer to that Bullet in our list
	// 	i++;
	// 	this->addChild(bullets[i]);
	// 	bullets[i]->position = player->position;

	// 	this->addChild(bullet);
	// 	bullet->position = player->position;
	// }

	// preven leave the screen.
	if (player -> position.x + player->sprite()->size.x /2 > SWIDTH)
    {
        player->position.x += -1;
    }
    if (player -> position.x - player->sprite()->size.x /2  < 0)
    {
        player->position.x -= -1;
    }

    //Y Axis
    if (player -> position.y + player->sprite()->size.y /2 > SHEIGHT)
    {
        player->position.y += -1;
    }
    if (player -> position.y - player->sprite()->size.y /2  < 0)
    {
        player->position.y -= -1;
    }

	// ###############################################################
	// Rotate color
	// ###############################################################
	// if (t.seconds() > 0.0333f) {
	// 	RGBAColor color = myentity->sprite()->color;
	// 	myentity->sprite()->color = Color::rotate(color, 0.01f);
	// 	t.start();
	// }
	// ###############################################################
	// Move to left to right ENEMY
	// ###############################################################
	enemy->position.x += enemySpeed * deltaTime;

	if (enemy->position.x + enemy->sprite()->size.x /2 > SWIDTH)
    {
    	enemySpeed = -1 * enemySpeed;
		//   cout << enemySpeed;

    }
    if (enemy-> position.x - enemy->sprite()->size.x /2  < 0)
    {
        enemySpeed = -1 * enemySpeed;
    }
}
