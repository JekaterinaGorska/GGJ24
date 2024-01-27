#include "Menus.h"

GameStates Menus::m_currentGameState = GameStates::Splash;

Menus::Menus(sf::RenderWindow& t_window) : window(t_window)
{
	//m_gamePlayScreen = new GamePlay;
}

void Menus::update(sf::Time& t_deltaTime)
{
	switch (m_currentGameState)
	{
	case GameStates::Splash:
		m_splashScreen.update();
		break;
	case GameStates::GamePlay:
		m_gamePlayScreen.update(t_deltaTime);
		break;
	default:
		break;
	}
}

void Menus::render(sf::RenderWindow& t_window)
{
	switch (m_currentGameState)
	{
	case GameStates::Splash:
		m_splashScreen.render(window);
		break;
	case GameStates::GamePlay:
		m_gamePlayScreen.render(window);
		break;
	default:
		break;
	}
}


void Menus::processInput(sf::Event& t_event)
{
	switch (m_currentGameState)
	{
	case GameStates::Splash:

		break;
	/*case GameStates::GamePlay:
		m_gamePlayScreen->processInput(t_event);
		break;*/
	default:
		break;
	}
}

void Menus::initialise(sf::Font& font)
{
	//Load here and call other screen initilaise methods
	//m_gamePlayScreen.initialise();
	m_splashScreen.initialise(font);
	myfont = font;
}

