#pragma once
#include <SFML/Graphics.hpp>
#include<vector>

class MunchieObject {
private:
	sf::RectangleShape munchieObject;

	sf::Sprite munchieSprite;
	sf::Texture muchieTexture;
public:
	MunchieObject();
	void update(sf::Time& t_deltaTime);   //updates entities in game
	void render(sf::RenderWindow& t_window); //draws sprites
	void initialise();  //initialises entities
	sf::Sprite getShape() { return munchieSprite; };

	void setOffScreen() { munchieSprite.setPosition(-1000, -1000); };

};