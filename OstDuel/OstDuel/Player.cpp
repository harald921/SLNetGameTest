#include "Player.h"

Player::Player(bool inIsLocalPlayer, bool inBottomSide)
{
	m_isLocalPlayer = inIsLocalPlayer;
	m_isBottomPlayer = inBottomSide;
	m_MachineGun = MachineGun(Vector2(0, -(float)inBottomSide));
	CreateBody(inBottomSide);
}


void Player::Update(float inDeltaTime)
{
	if (m_isLocalPlayer)
		HandleInput(inDeltaTime);
	else
		CheckForMessage();

	Move(inDeltaTime);

	m_MachineGun.Update(m_CurrentPlayerActions.Firing_Machinegun, m_Shape.getPosition(), inDeltaTime);
}

void Player::Render(sf::RenderWindow* inRenderWindow)
{
	inRenderWindow->draw(m_Shape);
	m_MachineGun.Render(inRenderWindow);
}


void Player::HandleInput(float inDeltaTime)
{
	m_CurrentPlayerActions.Firing_Machinegun = false;
	m_CurrentPlayerActions.Firing_Rocket	 = false;
	m_CurrentPlayerActions.Moving_Left		 = false;
	m_CurrentPlayerActions.Moving_Right		 = false;

	if (KEYPRESS_LEFT)
		m_CurrentPlayerActions.Moving_Left = true;

	if (KEYPRESS_RIGHT) 
		m_CurrentPlayerActions.Moving_Right = true;

	if (KEYPRESS_FIRE)
		m_CurrentPlayerActions.Firing_Machinegun = true;
}


void Player::CreateBody(bool inBottomSide)
{
	m_Shape = sf::RectangleShape();

	m_Shape.setSize(Vector2(PLAYER_SIZE_X, PLAYER_SIZE_Y));
	m_Shape.setOutlineThickness(-PLAYER_OUTLINE_THICKNESS);
	
	m_Shape.setOutlineColor(sf::Color(PLAYER_OUTLINE_RGB));

	if (m_isLocalPlayer)
		m_Shape.setFillColor(sf::Color(LOCAL_PLAYER_RGB));
	else
		m_Shape.setFillColor(sf::Color(OTHER_PLAYER_RGB));

	m_Shape.setOrigin(m_Shape.getSize() / 2.0f);

	if (inBottomSide)
		m_Shape.setPosition(Vector2(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT - (PLAYER_SIZE_Y /2.0f)- PLAYER_DISTANCE_FROM_BORDER));
	else
		m_Shape.setPosition(Vector2(WINDOW_WIDTH / 2.0f, PLAYER_SIZE_X - PLAYER_DISTANCE_FROM_BORDER)); 
}


void Player::Move(float inDeltaTime)
{
	// Move the player in a direction
	if (m_CurrentPlayerActions.Moving_Left)
		m_Shape.setPosition(Vector2(m_Shape.getPosition().x - (PLAYER_MOVE_SPEED * inDeltaTime), m_Shape.getPosition().y));

	if (m_CurrentPlayerActions.Moving_Right)
		m_Shape.setPosition(Vector2(m_Shape.getPosition().x + (PLAYER_MOVE_SPEED * inDeltaTime), m_Shape.getPosition().y));

	// Make sure the player doesn't go outside of the screen
	if (m_Shape.getPosition().x < 0)
		m_Shape.setPosition(Vector2(0, m_Shape.getPosition().y));
	else if (m_Shape.getPosition().x > WINDOW_WIDTH)
		m_Shape.setPosition(Vector2(WINDOW_WIDTH, m_Shape.getPosition().y));
}
