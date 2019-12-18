#pragma once
#include "kage2dutil/gameobject.h"
#include "SFML/Graphics.hpp"

class Ball : public kage::GameObject
{
private:
	float moveX;
	float moveY;
	float force;
	bool flipX;

public:
	Ball();
	~Ball();
	void update(float deltaT);
	void onCollision(GameObject* obj);
	void onCollision(b2Fixture* fix);
};