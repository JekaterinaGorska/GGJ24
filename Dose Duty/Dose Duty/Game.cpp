
#include "Game.h"
#include <iostream>

Game::Game() :
	m_window{ sf::VideoMode{ 1900U, 1250U, 32U }, "Dose Duty" },
	m_exitGame{false} //when true game will exit
	//m_playerMovement{ 0.0f, 0.0f }// Initialize player movement
{
	//setupFontAndText();  
	setupWallpaper();
	setupPlayer();
	setupFriends();
	setupCouch();
}

Game::~Game()
{
}

void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}

//void Game::setupFontAndText()
//{
//	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
//	{
//		std::cout << "problem loading arial black font" << std::endl;
//	}
//	m_welcomeMessage.setFont(m_ArialBlackfont);
//	m_welcomeMessage.setString("SFML Game");
//	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
//	m_welcomeMessage.setPosition(40.0f, 40.0f);
//	m_welcomeMessage.setCharacterSize(80U);
//	m_welcomeMessage.setOutlineColor(sf::Color::Red);
//	m_welcomeMessage.setFillColor(sf::Color::Black);
//	m_welcomeMessage.setOutlineThickness(3.0f);
//
//}



void Game::setupWallpaper()
{
	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\room.png"))
	{
		std::cout << "Problem loading background" << std::endl;
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);
	//m_backgroundSprite.setPosition(0, 0);
	m_backgroundSprite.setScale(static_cast<float>(m_window.getSize().x) / m_backgroundTexture.getSize().x,
		static_cast<float>(m_window.getSize().y) / m_backgroundTexture.getSize().y);

}

void Game::setupPlayer()
{
	m_player.setSize(sf::Vector2f(16, 32));
	m_player.setOutlineColor(sf::Color::Magenta);
	m_player.setFillColor(sf::Color::Cyan);
	m_player.setOutlineThickness(5);
	m_player.setPosition(100, 100);
	m_player.setScale(5.0f, 5.0f);

	playerSpeed = 200.0f;
}

void Game::setupFriends()
{
	m_friend.setSize(sf::Vector2f(16, 32));
	m_friend.setOutlineColor(sf::Color::Cyan);
	m_friend.setFillColor(sf::Color::Yellow);
	m_friend.setOutlineThickness(3);
	m_friend.setPosition(200, 600);
	m_friend.setScale(5.0f, 5.0f);
}

void Game::setupCouch()
{
	if (!m_couchTexture.loadFromFile("ASSETS\\IMAGES\\couch.png"))
	{
		std::cout << "Problem loading file" << std::endl;
	}
	m_couchSprite.setTexture(m_couchTexture);
	m_couchSprite.setPosition(1155, 500);
	m_couchSprite.setScale(9.0f, 9.0f);

}



void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}

}


void Game::render()
{
	m_window.clear();
	m_window.draw(m_backgroundSprite);
	m_window.draw(m_couchSprite);
	m_window.draw(m_player);
	m_window.draw(m_friend);
	
	m_window.display();
}

void Game::update(sf::Time t_deltaTime)
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

	if (m_exitGame)
	{
		m_window.close();
	}
}