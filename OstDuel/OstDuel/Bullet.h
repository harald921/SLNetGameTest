#pragma once

#include "SFML\Graphics.hpp"
#include "Defines.h"

class Bullet
{
public:
	Bullet(Vector2 inSpawnPosition, Vector2 inDirection);
	~Bullet() {}
	
	void Update(float inDeltaTime);
	void Render(sf::RenderWindow* inWindow);
	bool IsAlive() { return m_IsAlive; }

private:
	void CreateShape(Vector2 inSpawnPosition);
	void CheckCollision();
	void Move(float inDeltaTime);

	bool m_IsAlive;
	float m_LifeTime;

	sf::CircleShape m_Shape;
	Vector2 m_Velocity;
};

