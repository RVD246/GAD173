#include "GridMake.h"

void GridMake::grid(sf::RenderWindow& window)
{
	int hlineno = 0;
	int vlineno = 0;
	for (size_t i = 0; i < window.getSize().y; )
	{
		Horizontallines.emplace_back(sf::RectangleShape(sf::Vector2f(window.getSize().x, 5)));
		Horizontallines[hlineno].setPosition(0, 0 + (Horizontalgap * hlineno));
		i = Horizontalgap * hlineno;
		hlineno++;
	}
	for (size_t i = 0; i < window.getSize().x; )
	{
		Verticallines.emplace_back(sf::RectangleShape(sf::Vector2f(5, window.getSize().y)));
		Verticallines[vlineno].setPosition(0 + (Verticalgap * vlineno), 0);
		i = Verticalgap * vlineno;
		vlineno++;
	}
}

GridMake::GridMake()
{
	Verticalgap = 160;
	Horizontalgap = 54;
}

void GridMake::drawgrid(sf::RenderWindow& window)
{
	for (size_t i = 0; i < Horizontallines.size(); i++)
	{
		window.draw(Horizontallines[i]);
	}
	for (size_t i = 0; i < Verticallines.size(); i++)
	{
		window.draw(Verticallines[i]);
	}
}