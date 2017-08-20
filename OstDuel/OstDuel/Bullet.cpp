#include "Bullet.h"



Bullet::Bullet(Vector2 inSpawnPosition, Vector2 inDirection)
{
	m_IsAlive = true;
	m_Velocity = inDirection * BULLET_TRAVEL_SPEED;
	m_LifeTime = BULLET_LIFETIME;
	CreateShape(inSpawnPosition);
}

void Bullet::Update(float inDeltaTime)
{
	Move(inDeltaTime);
	CheckCollision();

	// Decrease lifetime and check whether or not it is less than or equals to 0
	if ((m_LifeTime -= inDeltaTime) <  0)
		m_IsAlive = false;
}

void Bullet::Render(sf::RenderWindow* inWindow)
{
	inWindow->draw(m_Shape);
}



void Bullet::CreateShape(Vector2 inSpawnPosition)
{
	m_Shape = sf::CircleShape();
	
	m_Shape.setRadius(BULLET_SIZE);
	m_Shape.setFillColor(sf::Color(BULLET_RGB));
	m_Shape.setOrigin(Vector2(BULLET_SIZE / 2, BULLET_SIZE / 2));
	m_Shape.setPosition(inSpawnPosition);

}

void Bullet::Move(float inDeltaTime)
{
	Vector2 newPosition = m_Shape.getPosition() + (m_Velocity * inDeltaTime);
	m_Shape.setPosition(newPosition);
}

void Bullet::CheckCollision()
{

}