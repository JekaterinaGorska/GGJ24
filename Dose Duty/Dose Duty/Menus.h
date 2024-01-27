#pragma once
#include <SFML/Graphics.hpp>
#include"Splash.h"
#include"GamePlay.h"


enum class GameStates
{
	Splash,
	GamePlay
};


class Menus
{
public:
	Menus(sf::RenderWindow& t_window);
	void update(sf::Time& t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processInput(sf::Event& t_event);
	void initialise(sf::Font &font);

	sf::Font myfont;
	sf::RenderWindow& window;
	sf::Clock clock;
	static GameStates m_currentGameState;

private:
	sf::RenderWindow m_window;
	Splash m_splashScreen;

	GamePlay m_gamePlayScreen;
};

