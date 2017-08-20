#pragma once

#include "SFML\Graphics.hpp"

#include "Bullet.h"
#include "Defines.h"

class MachineGun
{
public:
	MachineGun() { }
	MachineGun(Vector2 inDirection);
	~MachineGun() { }

	void Update(bool inIsFiring, Vector2 inPosition, float inDeltaTime);
	void Render(sf::RenderWindow* inRenderWindow);

private:
	void Fire(Vector2 inOrigin, Vector2 inDirection);
	
	std::vector<Bullet> m_BulletsInAir;

	Vector2 m_Direction; // The direction the weapon is pointing
	Vector2 m_Position;	 // The current position of the weapon

	float m_CooldownTimer = 0;
};

