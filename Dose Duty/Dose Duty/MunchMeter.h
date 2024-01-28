#pragma once

#include <SFML/Graphics.hpp>
#include<vector>

class MunchMeter
{
private:
	float currentMuchMeter = 100;
	const int MAX_MUNCH_METER = 100;
	sf::Clock munchieClock;

	sf::RectangleShape MunchMeterSprite;
	sf::RectangleShape munchMeterOutline;
public:
	MunchMeter();
	void update(sf::Time& t_deltaTime);   //updates entities in game
	void render(sf::RenderWindow& t_window); //draws sprites
	void initialise();  //initialises entities
	void setPosition(sf::Vector2f t_vec);
	void gainMunchies();
	void setMeterColor();
	void lessenMunchies();

};