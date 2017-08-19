#include "Game.h"

#include "Defines.h"
#include "Player.h"

Game::Game()
{
	m_pWindow = CreateWindow();

	m_DeltaClock = sf::Clock();

	m_pPlayers[0] = new Player(true, true);

	MainLoop();
}

Game::~Game() {}


void Game::MainLoop()
{
	while (m_pWindow->isOpen())
	{
		float deltaTime = m_DeltaClock.restart().asSeconds();
		Update(deltaTime);
		Render();
	}
}

void Game::Update(float inDeltaTime)
{
	sf::Event event;
	while (m_pWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_pWindow->close();

		if (event.type == sf::Event::GainedFocus)
			m_WindowHasFocus = true;

		if (event.type == sf::Event::LostFocus)
			m_WindowHasFocus = false;
	}

	for (int i = 0; i < 2; i++)
		if (m_pPlayers[i])
			m_pPlayers[i]->Update(inDeltaTime);
}

void Game::Render()
{
	m_pWindow->clear(sf::Color(BACKGROUND_RGB));

	for (int i = 0; i < 2; i++)
		if (m_pPlayers[i])
			m_pPlayers[i]->Render(m_pWindow);
	
	m_pWindow->display();
}


sf::RenderWindow* Game::CreateWindow()
{
	sf::RenderWindow* pNewRenderWindow = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
	pNewRenderWindow->requestFocus();
	pNewRenderWindow->setVerticalSyncEnabled(VSYNC_ENABLED);

	return pNewRenderWindow;
}