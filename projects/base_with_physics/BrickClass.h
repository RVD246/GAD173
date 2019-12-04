#pragma once

#include<app.h>
#include "kage2dutil/gameobject.h"

class BrickClass: public kage::GameObject
{
public:
	BrickClass();
	void setposition(sf::Vector2f);
	void setsprite(std::string&);
	void reset();
	int collidercode;
	b2Vec2 Collider_Position;
	b2Vec2 Collider_Size;
};

