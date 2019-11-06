#pragma once

#include "app.h"
#include<vector>
#include <GridMake.h>
#include <BrickClass.h>
#include <fstream>


class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	bool hovergui;
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();
	sf::Sprite *m_backgroundSprite;
	int Verticalgap;
	int Horizontalgap;	
	int ReplaceNo;
	int xPos;
	int yPos; 
	const int cellsx = 16;
	const int cellsy = 20;
	GridMake thegrid;
	BrickClass* bricks[320];
	float mouseX;
	float mouseY;
	float mousebyspriteX;
	float mousebyspriteY;
	std::string spritename;
};
