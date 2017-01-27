#include "Game.h"
#include <iostream>

/// <summary>
/// James Condon 
/// C00207200
/// </summary>

// Updates per milliseconds
static double const MS_PER_UPDATE = 10.0;

/// <summary>
/// @brief Default constructor.
/// 
/// Create a new window and initialise member objects.
/// </summary>
/// 
Game::Game():
	m_window(sf::VideoMode(900, 600, 32), "Credits"),
	m_currentGameState(GameState::Splash)

{
	if (!m_comicSans.loadFromFile("c:/windows/fonts/comic.ttf"))
	{
		std::cout << "problem loading font" << std::endl;
	}
	m_splashScreen = new Splash(*this, m_comicSans);
	
}
Game::~Game()
{
	delete(m_splashScreen);
	std::cout << "destructing game" << std::endl;
}

/// <summary>
/// Main game entry point - runs until user quits.
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);

	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}
		render();
	}
}
/// <summary>
/// setd the current game state 
/// </summary>
/// <param name="gameState"></param>
void Game::setGameState(GameState gameState)
{
	m_currentGameState = gameState;
}

/// <summary>
/// @brief Check for events
/// 
/// Allows window to function and exit. 
/// Events are passed on to the Game::processGameEvents() method
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		if (event.type == sf::Event::KeyPressed && m_currentGameState == GameState::Splash)
		{
			m_splashScreen->changeScreen();
		}
	}
}


/// <summary>
/// Method to handle all game updates
/// </summary>
/// <param name="time">update delta time</param>
void Game::update(sf::Time time)
{
	switch (m_currentGameState)
	{
	case GameState::None:
		m_splashScreen->print(time);
		m_window.close();
		break;
	case GameState::Splash:
		processEvents();
		m_splashScreen->update(time);
		break;
	default:
		break;

	}
}


/// <summary>
/// @brief draw the window for the game.
/// 
/// draw buttons and text on left side
/// </summary>
void Game::render()
{
	switch (m_currentGameState)
	{
	
	case GameState::Splash:
		m_splashScreen->render(m_window);
		break;
	default:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.display();
		break;

	}

	
}


