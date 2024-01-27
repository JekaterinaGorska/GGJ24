
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	//void setupFontAndText();
	void setupWallpaper();
	void setupPlayer();
	void setupFriends();
	void setupCouch();

	sf::RenderWindow m_window; 
	sf::Font m_ArialBlackfont; 

	sf::RectangleShape m_player;
	float playerSpeed;

	sf::RectangleShape m_friend;

	sf::Sprite m_couchSprite;
	sf::Texture m_couchTexture;

	sf::Sprite m_backgroundSprite;
	sf::Texture m_backgroundTexture; 
	

	bool m_exitGame; 

};

#endif // !GAME_HPP

