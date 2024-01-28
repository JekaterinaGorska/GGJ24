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
	t_window.draw(munchieObject);
}

void MunchieObject::initialise()
{
	munchieObject.setSize(sf::Vector2f(20, 20));
	munchieObject.setFillColor(sf::Color::Red);
	munchieObject.setPosition(300, 600);
	munchieObject.setOrigin(10, 10);
}



