#include "Player.h"
#include <algorithm>


Player::Player(bool inIsLocalPlayer, bool inBottomSide)
{
	m_isLocalPlayer = inIsLocalPlayer;
	CreateBody(inBottomSide);
}

Player::~Player() {}


void Player::Update(float inDeltaTime)
{
	if (m_isLocalPlayer)
		HandleInput(inDeltaTime);
	else
		CheckForMessage();

	Move(inDeltaTime);
}

void Player::Render(sf::RenderWindow* inRenderWindow)
{
	inRenderWindow->draw(*m_pShape);
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
}


void Player::CreateBody(bool inBottomSide)
{
	m_pShape = new sf::RectangleShape();

	m_pShape->setSize(Vector2(PLAYER_SIZE_X, PLAYER_SIZE_Y));
	m_pShape->setOutlineThickness(-PLAYER_OUTLINE_THICKNESS);
	
	m_pShape->setOutlineColor(sf::Color(PLAYER_OUTLINE_RGB));

	if (m_isLocalPlayer)
		m_pShape->setFillColor(sf::Color(LOCAL_PLAYER_RGB));
	else
		m_pShape->setFillColor(sf::Color(OTHER_PLAYER_RGB));

	m_pShape->setOrigin(m_pShape->getSize() / 2.0f);

	if (inBottomSide)
		m_pShape->setPosition(Vector2(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT - (PLAYER_SIZE_Y /2.0f)- PLAYER_DISTANCE_FROM_BORDER));
	else
		m_pShape->setPosition(Vector2(WINDOW_WIDTH / 2.0f, PLAYER_SIZE_X - PLAYER_DISTANCE_FROM_BORDER)); 
}


void Player::Move(float inDeltaTime)
{
	if (m_CurrentPlayerActions.Moving_Left)
		m_pShape->setPosition(Vector2(m_pShape->getPosition().x - (PLAYER_MOVE_SPEED * inDeltaTime), m_pShape->getPosition().y));

	if (m_CurrentPlayerActions.Moving_Right)
		m_pShape->setPosition(Vector2(m_pShape->getPosition().x + (PLAYER_MOVE_SPEED * inDeltaTime), m_pShape->getPosition().y));
}

void Player::FireMachineGun(float inDeltaTime)
{

}

void Player::FireRocket(float inDeltaTime)
{

}