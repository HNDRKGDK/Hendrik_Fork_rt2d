/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef ENEMYBLOCK_H
#define ENEMYBLOCK_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class EnemyBlock : public Entity
{
public:

	//test vector right

	/// @brief Constructor
	EnemyBlock();
	/// @brief Destructor
	virtual ~EnemyBlock();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
	float enemySpeed;
};

#endif /* MYENTITY_H */