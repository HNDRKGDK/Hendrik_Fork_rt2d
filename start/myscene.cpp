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
#include "collider.h"

using namespace std;

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	// create single instance player.
	player = new Player();
	player->position = Point2(SWIDTH/2, SHEIGHT/1.1);

	enemy = new EnemyBlock();
	enemy->position = Point2(SWIDTH/2, SHEIGHT/5);

	// bSullet = new Bullet;

	// create the scene 'tree'
	// add player to this Scene as a child.
	this->addChild(player);
	this->addChild(enemy);
	// this->addchild(bullet);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(enemy);
	this->removeChild(player);

	delete enemy;
	delete player;
}

void MyScene::update(float deltaTime)
{

	// // check colliders against each other
	// if( Collider::circle2circle(player.playercircle, bullet->bulletcircle) ) {
	// 	bullet->bulletcircle->line()->color = RED;
	// }
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	//Player bullet list
	for (int i = player->playerbullets.size() - 1; i >= 0; i--) {
        if (player->playerbullets[i]->position.x > SWIDTH || player->playerbullets[i]->position.x < 0 || player->playerbullets[i]->position.y < 0 || player->playerbullets[i]->position.y > SHEIGHT)
        {
            this->removeChild(player->playerbullets[i]);
            delete player->playerbullets[i];
            player->playerbullets.erase(player->playerbullets.begin() + i);
            std::cout << "player bullet deleted" << std::endl;
        }
	}

	//Enemy bullet list
	for (int i = enemy->enemybullets.size() - 1; i >= 0; i--) {
        if (enemy->enemybullets[i]->position.x > SWIDTH || enemy->enemybullets[i]->position.x < 0 || enemy->enemybullets[i]->position.y < 0 || enemy->enemybullets[i]->position.y > SHEIGHT)
        {
            this->removeChild(enemy->enemybullets[i]);
            delete enemy->enemybullets[i];
            enemy->enemybullets.erase(enemy->enemybullets.begin() + i);
            std::cout << "player bullet deleted" << std::endl;
        }
	}

	// prevent player from leaving the screen
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

	
	enemy->position.x += enemySpeed * deltaTime;

	if (enemy->position.x + enemy->sprite()->size.x /2 > SWIDTH)
    {
    	enemySpeed = -1 * enemySpeed;

    }
    if (enemy-> position.x - enemy->sprite()->size.x /2  < 0)
    {
        enemySpeed = -1 * enemySpeed;
    }
}
