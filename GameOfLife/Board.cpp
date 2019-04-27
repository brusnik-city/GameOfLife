#include <iostream>
#include <fstream>
#include <string>

#include "Board.h"

Board::Board()
{
}

Board::~Board()
{
}
Board::Board(const Board& oldBoard)
{
	m_board = oldBoard.GetBoard();
}

void Board::FillBoardFromFile()
{
	char field;
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
	}
	else
		std::cout << "nie otworzono";
}

void Board::PrintBoard() const
{
	for (auto line = m_board.begin(); line != m_board.end(); ++line)
	{
		for (auto field = ++(*line).begin(); field != --(*line).end(); ++field)
		{
			if (*field == 0) std::cout << "_";
			else std::cout << "X";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

size_t Board::Size() const
{
	return m_board.size();
}

size_t Board::SizeY() const
{
	return m_board[0].size();
}

int& Board::Value(int x, int y)
{
	return m_board.at(x).at(y);
}

void Board::SetValue(int x, int y, int value)
{
	m_board.at(x).at(y) = value;
}

std::vector<std::vector<int>> Board::GetBoard() const
{
	return m_board;
}