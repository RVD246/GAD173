#include "BrickClass.h"

BrickClass::BrickClass()
{
	m_sprite = kage::TextureManager::getSprite("data/brik.png");
}

void BrickClass::setposition(sf::Vector2f pos)
{
	m_position = pos;
}
