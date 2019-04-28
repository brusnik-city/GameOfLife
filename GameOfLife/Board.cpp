#include <iostream>
#include <fstream>
#include <string>

#include "Board.h"

Board::Board(){}

Board::~Board(){}

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
		while (gameFile.get(field))
		{
			line.push_back(static_cast<int>(field - 48));
			if (field == '\n')
			{
				line.pop_back();
				m_board.push_back(line);
				line.clear();
			}
		}
		m_board.push_back(line);
		line.clear();
	}
	else
		std::cout << "nie otworzono";
}

size_t Board::SizeX() const
{
	return m_board[0].size();
}

size_t Board::SizeY() const
{
	return m_board.size();
}

int& Board::Value(int x, int y)
{
	return m_board.at(y).at(x);
}

void Board::SetValue(int x, int y, int value)
{
	m_board.at(y).at(x) = value;
}

std::vector<std::vector<int>> Board::GetBoard() const
{
	return m_board;
}