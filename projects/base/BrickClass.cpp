#include "BrickClass.h"

BrickClass::BrickClass()
{
	m_sprite = kage::TextureManager::getSprite("data/transparentbrik.png");
}

void BrickClass::setposition(sf::Vector2f pos)
{
	m_position = pos;
}

void BrickClass::setsprite(std::string &filename)
{
	m_sprite = kage::TextureManager::getSprite(filename);
}

void BrickClass::reset()
{
	m_sprite->setTexture(*kage::TextureManager::getTexture("data/transparentbrik.png"));
}