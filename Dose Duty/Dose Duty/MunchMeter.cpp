#include "MunchMeter.h"

MunchMeter::MunchMeter()
{
	initialise();
}

void MunchMeter::update(sf::Time& t_deltaTime)
{
	gainMunchies();
	setMeterColor();
}

void MunchMeter::render(sf::RenderWindow& t_window)
{
	t_window.draw(MunchMeterSprite);
	t_window.draw(munchMeterOutline);
}

void MunchMeter::initialise()
{
	MunchMeterSprite.setSize(sf::Vector2f(MAX_MUNCH_METER * 2, 20));
	MunchMeterSprite.setFillColor(sf::Color::Green);
	MunchMeterSprite.setPosition(100, 100);
	MunchMeterSprite.setOrigin(100, 10);

	munchMeterOutline.setSize(sf::Vector2f(MAX_MUNCH_METER * 2, 20));
	munchMeterOutline.setFillColor(sf::Color::Transparent);
	munchMeterOutline.setOutlineColor(sf::Color::Black);
	munchMeterOutline.setOutlineThickness(2);
	munchMeterOutline.setOrigin(100, 10);
}

void MunchMeter::setPosition(sf::Vector2f t_vec)
{
	MunchMeterSprite.setPosition(sf::Vector2f(t_vec.x + 70, t_vec.y - 130));
	munchMeterOutline.setPosition(sf::Vector2f(t_vec.x +70, t_vec.y - 130));
}

void MunchMeter::gainMunchies()
{
	if (munchieClock.getElapsedTime().asSeconds() > 0.1f)
	{
		currentMuchMeter -= 0.5f;
		MunchMeterSprite.setSize(sf::Vector2f(currentMuchMeter * 2, 20));
		munchieClock.restart();
	}
}

void MunchMeter::setMeterColor()
{

	if (currentMuchMeter < 60 && currentMuchMeter > 45)
	{
		MunchMeterSprite.setFillColor(sf::Color(255, 127, 80));
	}
	if (currentMuchMeter < 45)
	{
		MunchMeterSprite.setFillColor(sf::Color::Red);
	}
}

void MunchMeter::lessenMunchies()
{
	currentMuchMeter += 15;
}
