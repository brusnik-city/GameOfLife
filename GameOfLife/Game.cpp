#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

#include "Game.h"

Game::Game() 
{
	m_board.FillBoardFromFile();
}

Game::~Game() {}

void Game::Run()
{
	
	PrintBoard();

	while (true)
	{
		PlayGame();
		PrintBoard();
		Sleep(1000);
	}
}

void Game::ReadFile()
{
	/*char field;
	std::ifstream gameFile;
	gameFile.open("Game.txt", std::ios::in);
	if (gameFile.is_open())
	{
		std::vector<int> line;
		line.push_back(0);
		while (gameFile.get(field))
		{
			line.push_back(static_cast<int>(field - 48));
			if (field == '\n')
			{
				line.pop_back();
				line.push_back(0);
				m_board.push_back(line);
				line.clear();
				line.push_back(0);
			}
		}
		line.push_back(0);
		m_board.push_back(line);
		line.clear();

		for (auto i = m_board.begin()->begin(); i != m_board.begin()->end(); i++)
			line.push_back(0);
		m_board.insert(m_board.begin(), line);
		m_board.push_back(line);
	}
	else
		std::cout << "nie otworzono";*/
}

void Game::PlayGame()
{
	int counter = 0;
	Board newBoard = m_board;
	for (int i = 1; i < m_board.Size() - 1; i++)
	{
		for (int j = 1; j < m_board.SizeY() - 1; j++)
		{
			if (m_board.Value(i-1,j-1) == 1) counter++;
			if (m_board.Value(i-1,j) == 1) counter++;
			if (m_board.Value(i-1,j+1) == 1) counter++;
			if (m_board.Value(i,j-1) == 1) counter++;
			if (m_board.Value(i,j+1) == 1) counter++;
			if (m_board.Value(i+1,j-1) == 1) counter++;
			if (m_board.Value(i+1,j) == 1) counter++;
			if (m_board.Value(i+1,j+1) == 1) counter++;
			if (m_board.Value(i, j) == 0 && counter == 3)
				newBoard.SetValue(i, j, 1);
			else if (m_board.Value(i, j) == 1 && (counter == 2 || counter == 3))
				newBoard.SetValue(i, j, 1);
			else
				newBoard.SetValue(i, j, 0);
			counter = 0;
		}
	}
	m_board = newBoard;
}

void Game::PrintBoard() const
{
/*	for (auto line = ++m_board.Begin(); line != --m_board.Size(); ++line)
	{
		for (auto field = ++(*line).begin(); field != --(*line).end(); ++field)
			std::cout << *field;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	*/
	}