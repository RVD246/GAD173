#include "ball.h"
#include "example.h"



Ball::Ball()
{
	m_sprite = kage::TextureManager::getSprite("data/ball.png");
	kage::centreOrigin(m_sprite);

	m_physicsStyle = GameObject::e_psBox2D;

	// Makes Box2D
	m_body = kage::Physics::BodyBuilder()
		.pos(0, 0)
		.userData(this)    
		.build();

	m_body->SetGravityScale(0);
	m_body->SetType(b2BodyType::b2_dynamicBody);


	// Collider
	kage::Physics::CircleBuilder()
		.radius(0.4f)
		.mass(1)
		.build(m_body); 

	moveX = 1;
	moveY = 1;
	force = 2;
	flipX = true;
}


Ball::~Ball()
{
}

void Ball::update(float deltaT)
{
	GameObject::update(deltaT);
	m_body->SetLinearVelocity(
		b2Vec2(
			moveX * force,
			moveY * force));

}

void Ball::onCollision(GameObject* obj)
{

}

void Ball::onCollision(b2Fixture* fix)
{
	if (m_sprite->getPosition().x < 35 || m_sprite->getPosition().x > 1875)
		moveX = moveX * -1;
	else
		moveY = moveY * -1;
}