#pragma once

#include "SFML\Graphics.hpp"
#include "Defines.h"

struct SCurrentPlayerActions
{
	bool Moving_Left;
	bool Moving_Right;

	bool Firing_Machinegun;
	bool Firing_Rocket;
};

class Player
{
public:
	Player(bool inIsLocalPlayer, bool inBottomSide);
	~Player();

	void Update(float inDeltaTime);
	void Render(sf::RenderWindow* inRenderWindow);

private:

	
	void HandleInput(float inDeltaTime);
	void CheckForMessage() { } // Denna är till för networking, och den ska användas istället för HandleMovement för att sätta spelarens olika PlayerActions

	void CreateBody(bool inBottomSide);

	void Move(float inDeltaTime);
	void FireMachineGun(float inDeltaTime);
	void FireRocket(float inDeltaTime);

	bool m_isLocalPlayer;

	SCurrentPlayerActions m_CurrentPlayerActions;

	sf::RectangleShape* m_pShape;
};

