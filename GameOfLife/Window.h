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
	sf::Text title;
	sf::RectangleShape titleRectangle;
	sf::RectangleShape naviRectangle;
	sf::RectangleShape deathCell;
	sf::RectangleShape aliveCell;
	sf::Text button[4];
	int width;
	int height;
	bool playGame = false;


};