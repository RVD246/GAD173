#pragma once
#include "BrickClass.h"

#include "app.h"
#include "kage2dutil/physics.h"
#include "ball.h"
#include <kage2dutil/gameobject.h>

class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();
	const int cellsx = 16;
	const int cellsy = 20;
	BrickClass* bricks[320];
	sf::Sprite *m_backgroundSprite;
	b2Vec2 direction;
	float force;
	Ball ball;

};
