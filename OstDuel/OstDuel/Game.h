#pragma once

#include "SFML\Graphics.hpp"

class Player;
class Game
{
public:
	Game();
	~Game();
	
private:
	void MainLoop();
	void Render();
	void Update(float inDeltaTime);

	sf::RenderWindow* CreateWindow();
	

	sf::RenderWindow* m_pWindow;
	sf::Clock m_DeltaClock;
	bool m_WindowHasFocus = true;
	Player* m_pPlayers[2];
	
};

