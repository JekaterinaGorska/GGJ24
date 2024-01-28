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
	friendMunchMeter.setPosition(m_friendSprite.getPosition());


	munchieObject.update(t_deltaTime);

	m_playerInteractionArea.setPosition(
		sf::Vector2f(
			m_playerSprite.getPosition().x - 50,
			m_playerSprite.getPosition().y - 50
	));

	ItemCollisions();

	m_friendInteractionArea.setPosition(sf::Vector2f(
		m_friendSprite.getPosition().x - 50,
		m_friendSprite.getPosition().y - 50
	));

	InteractWithFriend();

}
/// <summary>
/// draws everythign in the gameplay screen
/// </summary>
/// <param name="t_window"></param>
void GamePlay::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);
	t_window.draw(m_couchSprite);
	t_window.draw(m_backgroundChairSprite);
	t_window.draw(m_foregroundChairSprite);
	t_window.draw(m_loungeChairSprite);

	//t_window.draw(m_player);
	//st_window.draw(m_playerInteractionArea);
	t_window.draw(m_playerSprite);
	friendMunchMeter.render(t_window);
	//t_window.draw(m_friend);
	//t_window.draw(m_friendInteractionArea);
	t_window.draw(m_friendSprite);
	if(hasObject)
		t_window.draw(UIObject);
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
	setupForgroundChair();
	setupBackgroundChair();
	setupLounge();
	setupWallpaper();
	setUpUi();
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


	if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\SSNG.png"))
	{
		std::cout << "error loading sprite sheet";
	}

	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setPosition(100, 100);
	m_playerSprite.setTextureRect(sf::IntRect(0, 990, 176 * 2, 352 * 2));
	m_playerSprite.setOrigin(176, 352);
	m_playerSprite.setScale(0.5, 0.5);

	playerSpeed = 200.0f;

	m_playerInteractionArea.setSize(sf::Vector2f(200, 200));
	m_playerInteractionArea.setFillColor(sf::Color(145, 145, 145, 132));
	m_playerInteractionArea.setPosition(m_playerSprite.getPosition());

}

void GamePlay::setupFriends()
{
	if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\SSNG.png"))
	{
		std::cout << "error loading sprite sheet";
	}
	m_friendSprite.setTexture(m_playerTexture);
	m_friendSprite.setPosition(600, 275);
	m_friendSprite.setTextureRect(sf::IntRect(0, 0, 176 * 2, 352 * 2));
	m_friendSprite.setOrigin(176, 352);
	m_friendSprite.setScale(0.5, 0.5);

//	m_friend.setSize(sf::Vector2f(16, 32));
//	m_friend.setOutlineColor(sf::Color::Cyan);
//	m_friend.setFillColor(sf::Color::Yellow);
//	m_friend.setOutlineThickness(3);
//<<<<<<< HEAD
//	m_friend.setPosition(200, 200);
//	m_friend.setScale(3.0f, 3.0f);
//=======
//	m_friend.setPosition(200, 600);
//	m_friend.setScale(5.0f, 5.0f);

	m_friendInteractionArea.setSize(sf::Vector2f(200, 200));
	m_friendInteractionArea.setFillColor(sf::Color(145, 145, 145, 132));
	m_friendInteractionArea.setPosition(m_playerSprite.getPosition());
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
		{
			munchieObject.setOffScreen();
			hasObject = true;
		}
	}
}

void GamePlay::InteractWithFriend()
{
	if (m_friendInteractionArea.getGlobalBounds().intersects(m_playerInteractionArea.getGlobalBounds()))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && hasObject)
		{
			hasObject = false;
			friendMunchMeter.lessenMunchies();
			munchieObject.setBackToTable();
		}
	}
}

void GamePlay::setUpUi()
{
	if (!UIWaterTexture.loadFromFile("ASSETS\\IMAGES\\Water.png"))
	{
		std::cout << "Problem loading file" << std::endl;
	}
	UIObject.setTexture(UIWaterTexture);
	UIObject.setPosition(700, 0);
	UIObject.setScale(0.05, 0.05);
}






