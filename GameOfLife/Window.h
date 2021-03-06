#pragma once
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <thread>


class Window
{
public:
	Window();
	void Update();
	void Render();
private:

	std::shared_ptr<Game> game;
	void CreateNewGame(int pattern);
	std::vector<std::string> patterns;
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
	sf::Text nextPattern;
	unsigned int m_frame = 0;
	unsigned int m_fps = 0;
	unsigned int m_fps_limit = 50;
	int width;
	int height;
	bool playGame = false;
	bool start = true;
	int selectedPattern;


};