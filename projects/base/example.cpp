#include "example.h"

Example::Example(): App()
{	
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	spritename = "data/brik.png";
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	thegrid.grid(m_window);
	//BrickClass* brick = kage::World::build<BrickClass>();
	//brick->setposition(sf::Vector2f(0, 0));
	//BrickClass* bricks[304];
	int x = 16;
	int y = 20;
	int k = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			bricks[k] = kage::World::build<BrickClass>();
			bricks[k]->setposition(sf::Vector2f(160 * j, 54 * i));
			k++;
		}
	}
	return true;
}

void Example::update(float deltaT)
{
	if (!hovergui)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			mouseX = sf::Mouse::getPosition(m_window).x;
			mouseY = sf::Mouse::getPosition(m_window).y;
			mousebyspriteX = mouseX / 160;
			mousebyspriteY = mouseY / 54;
			xPos = (int)mousebyspriteX;
			yPos = (int)mousebyspriteY;
			ReplaceNo = xPos + (yPos * 16);

			bricks[ReplaceNo]->setsprite(spritename);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}
	
	ImGui::Begin("Menu");
	if (ImGui::Button("Save"))
	{
		
	}
	if (ImGui::Button("Load"))
	{

	}
	if (ImGui::Button("Add Tile"))
	{
		spritename = "data/brik.png";
	}
	if (ImGui::Button("Remove Tile"))
	{
		spritename = "data/transparentbrik.png";
	}
	if (ImGui::Button("Reset"))
	{
		int x = 16;
		int y = 20;
		int k = 0;
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				bricks[k]->reset();
				k++;
			}
		}
	}
	if (ImGui::Button("Exit"))
	{
		m_running = false;
	}
	if (ImGui::IsMouseHoveringWindow())
	{
		hovergui = true;
	}
	else
		hovergui = false;
	ImGui::End();	
}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);
	thegrid.drawgrid(m_window);
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

