#pragma once
#ifndef  GAME
#define GAME
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "Splash.h"

//each class is declared 
class Splash;
/// <summary>
/// enum is created to switch between the gamestates
/// </summary>
enum class
	GameState
{
	None,

	Splash,
};
class Game
{
public:
	Game();
	~Game();
	void run();
	GameState m_currentGameState;
	GameState m_previousGameState;
	void setGameState(GameState gameState);
protected:
	
	
	void update(sf::Time deltaTime);
	void render();
	void processEvents();
	

	// main window
	sf::RenderWindow m_window;
	//pointers set for all screens
	Splash *m_splashScreen;
	sf::Font m_comicSans;//font 
	
	
	
	

};
#endif // !GAME