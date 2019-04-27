#pragma once
#include "Game.h"
#include <SFML/Graphics.hpp>


class Window
{
public:
	Window();
	void Update();
	void Render();
private:

	Game *game;
	sf::RenderWindow *window;
	sf::RectangleShape rectangle;
	sf::Text title;
	sf::RectangleShape deathCell;
	sf::RectangleShape aliveCell;


};