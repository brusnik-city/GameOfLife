#include <iostream>
#include "Window.h"


Window::Window()
{	
	//create new game
	game = new Game();

	//get size
	width = game->GetSizeX()*41-1;
	height = game->GetSizeY()*41+150;
	//create new window
	window = new sf::RenderWindow(sf::VideoMode(width,height), "Adventure C++ Game of life!");
	window->clear(sf::Color::White);
	titleRectangle.setSize(sf::Vector2f(width, 99.f));
	titleRectangle.setFillColor(sf::Color(37, 77, 170));
	naviRectangle.setSize((sf::Vector2f(width, 50.f)));
	naviRectangle.setPosition(0.f, height - 50.f);
	naviRectangle.setFillColor(sf::Color(37, 77, 170));

	//font properties
	sf::Font font;
	if (!font.loadFromFile("Roboto-Medium.ttf"))
	{
		exit(-1);
	}

	//title
	title.setFont(font);
	title.setString("Game of life");
	title.setCharacterSize(32);
	title.setFillColor(sf::Color::White);
	title.setPosition(sf::Vector2f(width/2-90, 30.f));
	
	//Cells
	deathCell.setFillColor(sf::Color(120, 120, 120));
	aliveCell.setFillColor(sf::Color(37, 77, 170));
	deathCell.setSize(sf::Vector2f(40.f, 40.f));
	aliveCell.setSize(sf::Vector2f(40.f, 40.f));
	
	//buttons
	button[0].setFont(font);
	button[0].setCharacterSize(16);
	button[0].setFillColor(sf::Color::White);
	button[0].setPosition(10, height - 35);
	button[0].setString("Play");

	button[1].setFont(font);
	button[1].setCharacterSize(16);
	button[1].setFillColor(sf::Color(180,180,180));
	button[1].setPosition(60, height - 35);
	button[1].setString("|| Pause");

	button[2].setFont(font);
	button[2].setCharacterSize(16);
	button[2].setFillColor(sf::Color(180,180,180));
	button[2].setPosition(140, height - 35);
	button[2].setString("<< Backward");

	button[3].setFont(font);
	button[3].setCharacterSize(16);
	button[3].setFillColor(sf::Color(180,180,180));
	button[3].setPosition(250, height - 35);
	button[3].setString(">> Forward");

	//fps text
	fps.setFont(font);
	fps.setCharacterSize(16);
	fps.setFillColor(sf::Color::White);
	fps.setPosition(width - 60, height - 35);
	
	//fps slider
	sliderField.setSize(sf::Vector2f(100, 20));
	sliderField.setPosition(width - 200, height - 35);
	sliderField.setFillColor(sf::Color(180,180,180));
	sliderPosition.setSize(sf::Vector2f(20, 20));
	sliderPosition.setPosition(width - 160, height - 35);
	sliderPosition.setFillColor(sf::Color::White);

	//fps frame limit
	window->setFramerateLimit(m_fps_limit);

	//render first
	Render();
	//update game
	Update();
}
void Window::Update()
{
	//clock 
	sf::Clock clock;
	window->setFramerateLimit(10);

	//main loop
	while (window->isOpen())
	{
		//fps
		if (clock.getElapsedTime().asSeconds() >= 1.f)
		{
			m_fps = m_frame;
			m_frame = 0;
			clock.restart();
			fps.setString(std::to_string(m_fps).append(" fps"));
		}
		m_frame++;

		//play game
		if(playGame)
			game->PlayGame();

		//events
		sf::Event event;
		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window->close();
				break;
			case sf::Event::MouseButtonReleased:
				sf::Vector2i position = sf::Mouse::getPosition(*window);
				
				if (position.x < 55 && position.y > height - 40)
				{
					button[0].setFillColor(sf::Color(180,180,180));
					button[1].setFillColor(sf::Color::White);
					button[2].setFillColor(sf::Color(180,180,180));
					button[3].setFillColor(sf::Color(180,180,180));
					playGame = true;
				}
				else if (position.x <130 && position.y > height - 40)
				{
					button[0].setFillColor(sf::Color::White);
					button[1].setFillColor(sf::Color(180,180,180));
					button[2].setFillColor(sf::Color::White);
					button[3].setFillColor(sf::Color::White);
					playGame = false;
				}
				else if (position.x <240 && position.y >height - 40 && !playGame)
				{
					game->BackwardRestoreBoardToMemento();
				}
				else if (position.x <340 && position.y >height - 40 && !playGame)
				{
					game->ForwardRestoreBoardToMemento();
				}
				else if (position.x >width - 195 && position.x <width-105 && position.y >height - 35)
				{
					sliderPosition.setPosition(position.x - 10, sliderPosition.getPosition().y);
					m_fps_limit = (sliderPosition.getPosition().x - (width - 205))/2;
					window->setFramerateLimit(m_fps_limit);
				}
			}
		}
		//render window
		Render();
	}
}

void Window::Render()
{
	window->clear(sf::Color::White);
	window->draw(titleRectangle);
	window->draw(naviRectangle);
	window->draw(title);
	window->draw(button[0]);
	window->draw(button[1]);
	window->draw(button[2]);
	window->draw(button[3]);
	window->draw(fps);
	window->draw(sliderField);
	window->draw(sliderPosition);
	

	//render cells
	for (int i = 0; i < game->GetSizeX(); i++)
	{
		for (int j = 0; j < game->GetSizeY(); j++)
		{
			if (game->GetCell(i, j))
			{
				aliveCell.setPosition(sf::Vector2f(41*i,100+41*j));
				window->draw(aliveCell);
			}
			else
			{
				deathCell.setPosition(sf::Vector2f(41 * i,100+ 41 * j));
				window->draw(deathCell);
			}
		}
	}
	
	//display window
	window->display();
}