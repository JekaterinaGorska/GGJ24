#pragma once
#include <SFML/Graphics.hpp>
#include<vector>



class GamePlay
{
public:
	GamePlay();
	void update(sf::Time& t_deltaTime);   //updates entities in game
	void render(sf::RenderWindow& t_window); //draws sprites
	void processInput(sf::Event& t_event); //checks input
	void initialise();  //initialises entities

private:

	void setupWallpaper();
	void setupPlayer();
	void setupFriends();
	void setupCouch();
	void setupForgroundChair();
	void setupBackgroundChair();
	void setupLounge();
	

	sf::RectangleShape m_player;
	float playerSpeed;

	sf::RectangleShape m_friend;

	sf::Sprite m_couchSprite;
	sf::Texture m_couchTexture;

	sf::Sprite m_foregroundChairSprite;
	sf::Texture m_foregroundChairTexture;

	sf::Sprite m_backgroundChairSprite;
	sf::Texture m_backgroundChairTexture;

	sf::Sprite m_loungeChairSprite;
	sf::Texture m_loungeChairTexture;

	sf::Sprite m_backgroundSprite;
	sf::Texture m_backgroundTexture;


	
};

