#include "Splash.h"
#include <iostream>

Splash::Splash(Game & game, sf::Font font) :
	m_game(&game),
	m_comicSans(font)
	
{

}

Splash::~Splash()
{
	std::cout << "destructing Splash" << std::endl;

}
void Splash::print(sf::Time deltaTime)
{
	m_cumulativeTime += deltaTime;
	std::cout << "My Game" << std::endl;
	if (m_cumulativeTime.asSeconds() >= 2)
	{
		m_window.close();
	}
}
void Splash::changeScreen()
{
	m_pressed = true;//sets to true if pressed 
}
void Splash::update(sf::Time deltaTime)
{
	m_cumulativeTime += deltaTime;//adds on the time

	if (m_cumulativeTime.asSeconds() >= 3)
	{
		//changes the gamestate to splash 
		m_game->setGameState(GameState::None);
	}
}

void Splash::render(sf::RenderWindow & window)
{
	window.clear(sf::Color(255, 255, 255, 255));
	window.display();
}