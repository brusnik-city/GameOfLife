#include "Window.h"

Window::Window()
{
	//create new game
	game = new Game();

	//get size
	//windowSize = game->getSize();
	//windowSize = sf::Vector2f(100.f, 100.f);
	//windowSize.y += 100.f;
	//create new window
	window = new sf::RenderWindow(sf::VideoMode(1280, 800), "Adventure C++ Game of life!");
	window->clear(sf::Color(66, 66, 66));
	rectangle.setSize(sf::Vector2f(1280.f, 100.f));
	rectangle.setFillColor(sf::Color(37, 77, 170));

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
	title.setPosition(sf::Vector2f(1280.f/2-40, 30.f));

	//Cells
	//deathCell.setFillColor(sf::Color::White);
	//aliveCell.setFillColor(sf::Color(37, 77, 170));

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
	window->clear(sf::Color(66, 66, 66));
	window->draw(rectangle);
	window->draw(title);

	//display window
	window->display();
}