#include "Splash.h"
#include"Menus.h"

void Splash::render(sf::RenderWindow& window)
{
	//window.draw(text);
	//window.draw(m_splashSprite);
}

void Splash::initialise(sf::Font& t_font)
{

	
	font = t_font;
	text.setFont(font);
	text.setCharacterSize(12);
	text.setFillColor(sf::Color::Magenta);
	text.setString("Dose Duty");
	text.setPosition(800 / 2 - 200, 600 / 2 - 100);

	
}

void Splash::update()
{
	if (m_clock.getElapsedTime() > licenseTime)
	{
		Menus::m_currentGameState = GameStates::GamePlay;
	}
}

void Splash::splashBackground()
{
	if (!m_splashTexture.loadFromFile("ASSETS\\IMAGES\\splashscreen.jpg"))
	{
		std::cout << "Problem loading file" << std::endl;
	}
	m_splashSprite.setTexture(m_splashTexture);
	m_splashSprite.setPosition(0, 0);
	m_splashSprite.setScale(static_cast<float>(800) / m_splashTexture.getSize().x,
		static_cast<float>(600) / m_splashTexture.getSize().y); //I changed the window size to literals
}
