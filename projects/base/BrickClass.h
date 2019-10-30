#pragma once

#include<app.h>
#include "kage2dutil/gameobject.h"

class BrickClass: public kage::GameObject
{
public:
	BrickClass();
	void setposition(sf::Vector2f);
	void setsprite(const std::string&);
	void reset();
};

