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
	// Initialise the physics system. Set the default gravity to 9.8m/s^2 down.
	kage::Physics::init(b2Vec2(0, 9.8));
	//// Floor, left wall and right wall static colliders.
	//kage::Physics::BoxBuilder().pos(kf::Vector2(15, 16)).size(30, 1).build(kage::Physics::getDefaultStatic());
	//kage::Physics::BoxBuilder().pos(kf::Vector2(0, 8)).size(1, 16).build(kage::Physics::getDefaultStatic());
	//kage::Physics::BoxBuilder().pos(kf::Vector2(30, 8)).size(1, 16).build(kage::Physics::getDefaultStatic());

	int k = 0;
	for (int i = 0; i < cellsy; i++)
	{
		for (int j = 0; j < cellsx; j++)
		{
			bricks[k] = kage::World::build<BrickClass>();
			bricks[k]->setposition(sf::Vector2f(160 * j, 54 * i));
			k++;
		}
	}

	//Loading from map
	{
		m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
		sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
		m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

		bool ismap;
		std::string line;
		std::string ch;
		std::ifstream tilemap("map.dat");
		int k = 0;
		if (tilemap.is_open())
		{
			while (getline(tilemap, line))
			{
				if (line == "[Map]")
				{
					ismap = true;
					continue;
				}

				if (ismap)
				{
					for (int i = 0; i < cellsx; i++)
					{
						ch = line.substr(i, 1);
						if (ch == "1")
						{
							bricks[k]->m_sprite->setTexture(*kage::TextureManager::getTexture("data/brik.png"));
							bricks[k]->collidercode = 1;
						}
						else
							if (ch == "0")
							{
								bricks[k]->m_sprite->setTexture(*kage::TextureManager::getTexture("data/transparentbrik.png"));
								bricks[k]->collidercode = 0;
							}
						k++;
					}
				}
			}
			tilemap.close();
		}
		else
			std::cout << "FILE DOES NOT EXIST!";

		for (int i=0;i<320;i++)
		{
			if (bricks[i]->collidercode == 1)
			{
				bricks[i]->Collider_Position.x = bricks[i]->m_position.x / 64.0f + ((160 / 64.0f) / 2.0f);
				bricks[i]->Collider_Position.y = bricks[i]->m_position.y / 64.0f + ((54 / 64.0f) / 2.0f);

				bricks[i]->Collider_Size.x = 160 / 64.0f;
				bricks[i]->Collider_Size.y = 54 / 64.0f;

				kage::Physics::BoxBuilder().pos(bricks[i]->Collider_Position).size(bricks[i]->Collider_Size).build(kage::Physics::getDefaultStatic());
			}
		}
	}

	return true;
}

void Example::update(float deltaT)
{
	// You need to update the physics system every game update

	kage::Physics::update(deltaT);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}


	ImGui::Begin("Kage2D");
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	ImGui::End();
}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);
	// The next line draws the physics debug info. This should be removed in a final release.
	kage::Physics::debugDraw(&m_window, 64);
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}	

