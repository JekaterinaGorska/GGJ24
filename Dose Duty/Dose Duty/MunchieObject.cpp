#include "MunchieObject.h"

MunchieObject::MunchieObject()
{
	initialise();
}

void MunchieObject::update(sf::Time& t_deltaTime)
{
}

void MunchieObject::render(sf::RenderWindow& t_window)
{
//	t_window.draw(munchieObject);
	t_window.draw(munchieSprite);
}

void MunchieObject::initialise()
{
	munchieObject.setSize(sf::Vector2f(40, 40));
	munchieObject.setFillColor(sf::Color::Red);
	munchieObject.setPosition(300, 600);
	munchieObject.setOrigin(10, 10);

	if (!muchieTexture.loadFromFile("ASSETS\\IMAGES\\Water.png"))
	{
		//std::cout << "Problem loading file" << std::endl;
	}
	munchieSprite.setTexture(muchieTexture);
	munchieSprite.setPosition(200, 300);
	munchieSprite.setScale(0.03, 0.03);
}



