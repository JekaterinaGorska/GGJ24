#pragma once
#include <SFML/Graphics.hpp>
#include<vector>
#include"MunchMeter.h"
#include"MunchieObject.h"


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
	void setUpObjects();
	void animatePlayer();

	void ItemCollisions();

	sf::RectangleShape m_player;
	float playerSpeed;

	sf::RectangleShape m_friend;

	sf::RectangleShape m_playerInteractionArea; 

	sf::Sprite m_couchSprite;
	sf::Texture m_couchTexture;

	sf::Sprite m_backgroundSprite;
	sf::Texture m_backgroundTexture;


	sf::Sprite m_playerSprite;
	sf::Texture m_playerTexture;
	int playerTime = 0;
	int playerFrame = 0;

	MunchieObject munchieObject;



	MunchMeter friendMunchMeter;
	
};

