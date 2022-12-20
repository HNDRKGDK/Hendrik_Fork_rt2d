/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>

#include "enemyblock.h"
#include "player.h"
#include "bullet.h"
#include "shape.h"


/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	int enemySpeed = 200;

private:
	/// @brief the rotating square in the middle of the screen
	//MyEntity* myentity;
	
	//Declare player
	Player* player;	
	//Declare bullet

	//declare enemy test
	EnemyBlock* enemy;

	Bullet* bullet;

	/// @brief a Timer to rotate the color every n seconds
	Timer t;

	// test squares
	// Shape* square1;
	// Shape* square2;
	// Shape* circle1;
	// Shape* circle2;
	
};

#endif /* SCENE00_H */
