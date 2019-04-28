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
	button[1].setFillColor(sf::Color::White);
	button[1].setPosition(60, height - 35);
	button[1].setString("II Pause");

	button[2].setFont(font);
	button[2].setCharacterSize(16);
	button[2].setFillColor(sf::Color::White);
	button[2].setPosition(140, height - 35);
	button[2].setString("<< Backward");

	button[3].setFont(font);
	button[3].setCharacterSize(16);
	button[3].setFillColor(sf::Color::White);
	button[3].setPosition(250, height - 35);
	button[3].setString(">> Forward");
	

	//render first
	Render();
	//update game
	Update();
}
void Window::Update()
{

	//main loop
	while (window->isOpen())
	{
		//play game
		game->PlayGame();

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