#pragma once

#include "app.h"
#include<vector>
#include <GridMake.h>
#include <BrickClass.h>

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
	sf::Sprite *m_backgroundSprite;
	std::vector<sf::RectangleShape> Horizontallines;
	std::vector<sf::RectangleShape> Verticallines;
	int Verticalgap;
	int Horizontalgap;
	GridMake thegrid;
	BrickClass* brick;
};
