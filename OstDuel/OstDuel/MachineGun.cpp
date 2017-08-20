#include "MachineGun.h"


MachineGun::MachineGun(Vector2 inDirection)
{
	m_Direction = inDirection;
}

void MachineGun::Update(bool inIsFiring, Vector2 inPosition, float inDeltaTime)
{
	m_Position = inPosition;

	m_CooldownTimer -= inDeltaTime; 
	if (inIsFiring && m_CooldownTimer <= 0)
	{
		Fire(m_Position, m_Direction);
		m_CooldownTimer = BULLET_FIRE_COOLDOWN;
	}

	// Update all the bullets that are fired from this weapon
	for (int i = (int)m_BulletsInAir.size() - 1; i >= 0; i--)
	{
		if (m_BulletsInAir[i].IsAlive())
			m_BulletsInAir[i].Update(inDeltaTime);
		else
			m_BulletsInAir.erase(m_BulletsInAir.begin() + i);
	}
}

void MachineGun::Render(sf::RenderWindow* inRenderWindow)
{
	// Render all the bullets that are fired from this weapon
	for each (Bullet bullet in m_BulletsInAir)
		bullet.Render(inRenderWindow);
}

void MachineGun::Fire(Vector2 inOrigin, Vector2 inDirection)
{
	m_BulletsInAir.emplace_back(Bullet(inOrigin, inDirection));
}

