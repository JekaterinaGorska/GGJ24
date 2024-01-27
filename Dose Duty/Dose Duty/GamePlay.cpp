#include "GamePlay.h"
#include <cmath>
#include"Menus.h"

GamePlay::GamePlay()
{
	initialise();
}

/// <summary>
/// updates every variable inside of gameplay
/// </summary>
/// <param name="t_deltaTime">time past</param>
void GamePlay::update(sf::Time& t_deltaTime)
{
	sf::Vector2f m_playerMovement{ 0.0f, 0.0f };

	// Player movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		m_player.move(0.0f, -playerSpeed * t_deltaTime.asSeconds());
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		m_player.move(-playerSpeed * t_deltaTime.asSeconds(), 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		m_player.move(0.0f, playerSpeed * t_deltaTime.asSeconds());
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		m_player.move(playerSpeed * t_deltaTime.asSeconds(), 0.0f);
	
	
	// Save the current position
	sf::Vector2f currentPosition = m_player.getPosition();

	// Update player position
	m_player.move(m_playerMovement);

	// Check for collision with the couch
	sf::FloatRect playerBoundingBox = m_player.getGlobalBounds();
	sf::FloatRect couchBoundingBox(
		m_couchSprite.getPosition().x,
		m_couchSprite.getPosition().y + m_couchSprite.getLocalBounds().height / 2.0f,
		m_couchSprite.getLocalBounds().width * 9.0f,
		m_couchSprite.getLocalBounds().height / 2.0f
	);

	// Check for collision before moving the player
	if (playerBoundingBox.intersects(couchBoundingBox))
	{
		// Revert the player's position to the previous position if a collision occurred
		m_player.setPosition(currentPosition);
	}
}
/// <summary>
/// draws everythign in the gameplay screen
/// </summary>
/// <param name="t_window"></param>
void GamePlay::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);
	t_window.draw(m_couchSprite);
	t_window.draw(m_player);
	t_window.draw(m_friend);
}

void GamePlay::processInput(sf::Event& t_event)
{
	
}

void GamePlay::initialise()
{
	setupCouch();
	setupFriends();
	setupPlayer();
	setupWallpaper();
}

void GamePlay::setupWallpaper()
{
	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\room.png"))
{
	std::cout << "Problem loading background" << std::endl;
}
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(0, 0);
	m_backgroundSprite.setScale(static_cast<float>(1920) / m_backgroundTexture.getSize().x,
	static_cast<float>(1080) / m_backgroundTexture.getSize().y); //I changed the window size to literals

}

void GamePlay::setupPlayer()
{
	m_player.setSize(sf::Vector2f(16, 32));
	m_player.setOutlineColor(sf::Color::Magenta);
	m_player.setFillColor(sf::Color::Cyan);
	m_player.setOutlineThickness(5);
	m_player.setPosition(100, 100);
	m_player.setScale(5.0f, 5.0f);

	playerSpeed = 200.0f;
}

void GamePlay::setupFriends()
{
	m_friend.setSize(sf::Vector2f(16, 32));
	m_friend.setOutlineColor(sf::Color::Cyan);
	m_friend.setFillColor(sf::Color::Yellow);
	m_friend.setOutlineThickness(3);
	m_friend.setPosition(200, 600);
	m_friend.setScale(5.0f, 5.0f);
}

void GamePlay::setupCouch()
{
	if (!m_couchTexture.loadFromFile("ASSETS\\IMAGES\\couch.png"))
	{
		std::cout << "Problem loading file" << std::endl;
	}
	m_couchSprite.setTexture(m_couchTexture);
	m_couchSprite.setPosition(1155, 500);
	m_couchSprite.setScale(9.0f, 9.0f);

}




