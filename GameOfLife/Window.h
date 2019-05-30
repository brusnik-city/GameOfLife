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
	sf::RectangleShape sliderField;
	sf::RectangleShape sliderPosition;
	sf::Text button[4];
	sf::Text fps;
	unsigned int m_frame = 0;
	unsigned int m_fps = 0;
	unsigned int m_fps_limit = 50;
	int width;
	int height;
	bool playGame = false;


};