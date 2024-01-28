#pragma once
#include <SFML/Graphics.hpp>
#include<vector>

class MunchieObject {
private:
	sf::RectangleShape munchieObject;
public:
	MunchieObject();
	void update(sf::Time& t_deltaTime);   //updates entities in game
	void render(sf::RenderWindow& t_window); //draws sprites
	void initialise();  //initialises entities
	sf::RectangleShape getShape() { return munchieObject; };

	void setOffScreen() { munchieObject.setPosition(-1000, -1000); };

};