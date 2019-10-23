#pragma once
#include<app.h>
#include<vector>

class GridMake
{
public:
	GridMake();
	std::vector<sf::RectangleShape> Horizontallines;
	std::vector<sf::RectangleShape> Verticallines;
	int Verticalgap;
	int Horizontalgap;
	void grid(sf::RenderWindow& window);
	void drawgrid(sf::RenderWindow& window);
};

