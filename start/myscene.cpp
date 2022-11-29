/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include "myscene.h"

using namespace std;

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentity = new MyEntity();
	myentity->position = Point2(SWIDTH/2, SHEIGHT/2);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentity);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;
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
	if (input()->getKeyDown(KeyCode::Space)) {
		myentity->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		myentity->scale = Point(1.0f, 1.0f);
	}

	//###############################################################
    // Movement/Rotate test
    // ###############################################################
    int rotateSpeed = 5;
	float moveSpeed = 500;

    //Up
    if (input()->getKey(KeyCode::W)) 
    {
        myentity->position.y -= moveSpeed * deltaTime;
        // cout << "Up";
    }
    //Down
    if (input()->getKey(KeyCode::S)) 
    {
        myentity->position.y += moveSpeed * deltaTime;
        // cout << "Down";
    }
    //Right
    if (input()->getKey(KeyCode::D)) 
    {
        myentity->position.x += moveSpeed * deltaTime;
        // cout << "Right";
    }
    //Left
    if (input()->getKey(KeyCode::A)) 
    {
        myentity->position.x -= moveSpeed * deltaTime;
        // cout << "Left";
    }

	  if (input()->getKey(KeyCode::Left)) 
    {
        myentity->rotation.z -= rotateSpeed * deltaTime;
        // cout << "Rotate Left";
    }  if (input()->getKey(KeyCode::Right)) 
    {
        myentity->rotation.z += rotateSpeed * deltaTime;
        // cout << "Rotate Right";
    }


	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = myentity->sprite()->color;
		myentity->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}
}
