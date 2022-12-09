/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>
#include "bullet.h"

/// @brief The MyEntity class is the Entity implementation.
class Player: public Entity
{
public:

	//test vector right

	/// @brief Constructor
	Player();
	/// @brief Destructor
	virtual ~Player();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	std::vector<Bullet*> bullets;

private:
	/* add your private declarations */
	Bullet* bullet;
};

#endif /* PLAYER_H */