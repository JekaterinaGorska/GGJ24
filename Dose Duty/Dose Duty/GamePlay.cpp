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
	t_window.draw(m_backgroundChairSprite);
	t_window.draw(m_foregroundChairSprite);
	t_window.draw(m_loungeChairSprite);
	
}

void GamePlay::processInput(sf::Event& t_event)
{
	
}

void GamePlay::initialise()
{
	setupCouch();
	setupFriends();
	setupPlayer();
	setupForgroundChair();
	setupBackgroundChair();
	setupLounge();
	setupWallpaper();
}

void GamePlay::setupWallpaper()
{
	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\backgrround_room.png"))
{
	std::cout << "Problem loading background" << std::endl;
}
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(0, 0);
	m_backgroundSprite.setScale(static_cast<float>(800) / m_backgroundTexture.getSize().x,
	static_cast<float>(600) / m_backgroundTexture.getSize().y); //I changed the window size to literals

}

void GamePlay::setupPlayer()
{
	m_player.setSize(sf::Vector2f(16, 32));
	m_player.setOutlineColor(sf::Color::Magenta);
	m_player.setFillColor(sf::Color::Cyan);
	m_player.setOutlineThickness(5);
	m_player.setPosition(400, 200);
	m_player.setScale(3.0f, 3.0f);

	playerSpeed = 200.0f;
}

void GamePlay::setupFriends()
{
	m_friend.setSize(sf::Vector2f(16, 32));
	m_friend.setOutlineColor(sf::Color::Cyan);
	m_friend.setFillColor(sf::Color::Yellow);
	m_friend.setOutlineThickness(3);
	m_friend.setPosition(200, 200);
	m_friend.setScale(3.0f, 3.0f);
}

void GamePlay::setupCouch()
{
	if (!m_couchTexture.loadFromFile("ASSETS\\IMAGES\\couch.png"))
	{
		std::cout << "Problem loading file" << std::endl;
	}
	m_couchSprite.setTexture(m_couchTexture);
	m_couchSprite.setPosition(480, 250);
	m_couchSprite.setScale(4.0f, 4.0f);

}

void GamePlay::setupForgroundChair()
{
	if (!m_foregroundChairTexture.loadFromFile("ASSETS\\IMAGES\\foreground_chair.png")) 
	{
		std::cout << "Problem loading file" << std::endl;
	}

	m_foregroundChairSprite.setTexture(m_foregroundChairTexture);
	m_foregroundChairSprite.setPosition(300, 400);
	m_foregroundChairSprite.setScale(3.5f, 3.5f);
	
}

void GamePlay::setupBackgroundChair()
{
	if (!m_backgroundChairTexture.loadFromFile("ASSETS\\IMAGES\\background_chair.png"))
	{
		std::cout << "Problem loading file" << std::endl;
	}

	m_backgroundChairSprite.setTexture(m_backgroundChairTexture);
	m_backgroundChairSprite.setPosition(300, 300);
	m_backgroundChairSprite.setScale(3.5f, 3.5f);

}

void GamePlay::setupLounge()
{
	if (!m_loungeChairTexture.loadFromFile("ASSETS\\IMAGES\\bench.png"))
	{
		std::cout << "Problem loading file" << std::endl;
	}
	m_loungeChairSprite.setTexture(m_loungeChairTexture);
	m_loungeChairSprite.setPosition(30, 300);
	m_loungeChairSprite.setScale(4.0f, 4.0f);

}






