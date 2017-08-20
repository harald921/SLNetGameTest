#pragma once

// Window settings
#define GAME_NAME "OstDuel"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 728
#define VSYNC_ENABLED true
#define FULLSCREEN false
#define BACKGROUND_RGB 0, 0, 0

// Player settings
#define PLAYER_MOVE_SPEED 200.0f

#define PLAYER_SIZE_X 50.0f
#define PLAYER_SIZE_Y 30.0f
#define PLAYER_OUTLINE_THICKNESS 3.0f
#define PLAYER_DISTANCE_FROM_BORDER 5.0f

#define PLAYER_OUTLINE_RGB 200, 200, 200
#define LOCAL_PLAYER_RGB 0, 0, 255
#define OTHER_PLAYER_RGB 255, 0, 0

// Bullet and rocket settings
#define BULLET_LIFETIME 5.0f
#define BULLET_SIZE 4
#define BULLET_TRAVEL_SPEED 500.0f
#define BULLET_FIRE_COOLDOWN 0.15f
#define BULLET_RGB 255, 255, 0

// Convenience
#define Vector2 sf::Vector2f

// Input

#define KEYPRESS_LEFT sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
#define KEYPRESS_RIGHT sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
#define KEYPRESS_FIRE sf::Keyboard::isKeyPressed(sf::Keyboard::X)