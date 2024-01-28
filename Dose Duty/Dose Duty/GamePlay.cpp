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
	{
		m_playerSprite.move(0.0f, -playerSpeed * t_deltaTime.asSeconds());
		animatePlayer();
		//m_playerSprite.setScale(1, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_playerSprite.move(-playerSpeed * t_deltaTime.asSeconds(), 0.0f);
		animatePlayer();
		//m_playerSprite.setScale(-1, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_playerSprite.move(0.0f, playerSpeed * t_deltaTime.asSeconds());
		animatePlayer();
		//m_playerSprite.setScale(-1, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_playerSprite.move(playerSpeed * t_deltaTime.asSeconds(), 0.0f);
		animatePlayer();
		//m_playerSprite.setScale(1, 1);
	}
	
	
	// Save the current position
	sf::Vector2f currentPosition = m_playerSprite.getPosition();

	// Update player position
	m_player.move(m_playerMovement);

	// Check for collision with the couch
	sf::FloatRect playerBoundingBox = m_playerSprite.getGlobalBounds();
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
		m_playerSprite.setPosition(currentPosition);
	}

	friendMunchMeter.update(t_deltaTime);
	friendMunchMeter.setPosition(m_friend.getPosition());


	munchieObject.update(t_deltaTime);

	m_playerInteractionArea.setPosition(
		sf::Vector2f(
			m_playerSprite.getPosition().x - 50,
			m_playerSprite.getPosition().y
	));

	ItemCollisions();
	

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
	t_window.draw(m_playerInteractionArea);
	t_window.draw(m_playerSprite);
	friendMunchMeter.render(t_window);
	t_window.draw(m_friend);
	munchieObject.render(t_window);
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


	if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\SSNG.png"))
	{
		std::cout << "error loading sprite sheet";
	}

	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setPosition(100, 100);
	m_playerSprite.setTextureRect(sf::IntRect(0, 990, 176 * 2, 352 * 2));
	m_playerSprite.setOrigin(176, 352);

	playerSpeed = 200.0f;

	m_playerInteractionArea.setSize(sf::Vector2f(300, 300));
	m_playerInteractionArea.setFillColor(sf::Color(145, 145, 145, 132));
	m_playerInteractionArea.setPosition(m_playerSprite.getPosition());

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

void GamePlay::setUpObjects()
{

}

void GamePlay::animatePlayer()
{
	playerTime++;
	if (playerTime > 7)
	{
		playerFrame++;
		if (playerFrame > 3) 
		{
			playerFrame = 0; 
		}
		playerTime = 0;
	}
	int col = playerFrame % 3; 
	int row = 990; 

	

	sf::IntRect rectSourceSprite;
	rectSourceSprite.height = 352 * 2;
	rectSourceSprite.width = 176 * 2;
	rectSourceSprite.left = col * rectSourceSprite.width;
	rectSourceSprite.top = 990;
	m_playerSprite.setTextureRect(rectSourceSprite);
	//m_playerSprite.setOrigin(m_playerSprite.getTextureRect().width / 2, m_playerSprite.getTextureRect().height / 2);

	std::cout << col * (352 * 2) << " , ";
}

void GamePlay::ItemCollisions()
{
	if (munchieObject.getShape().getGlobalBounds().intersects(m_playerInteractionArea.getGlobalBounds()))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			munchieObject.setOffScreen();
	}
}




