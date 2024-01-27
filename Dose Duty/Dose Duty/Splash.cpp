#include "Splash.h"
#include"Menus.h"

void Splash::render(sf::RenderWindow& window)
{
	window.draw(text);
}

void Splash::initialise(sf::Font& t_font)
{
	font = t_font;
	text.setFont(font);
	text.setCharacterSize(52);
	text.setFillColor(sf::Color::Red);
	text.setString("Splash Screen");
	text.setPosition(1920 / 2 - 200, 1080 / 2 - 100);
}

void Splash::update()
{
	if (m_clock.getElapsedTime() > licenseTime)
	{
		Menus::m_currentGameState = GameStates::GamePlay;
	}
}
