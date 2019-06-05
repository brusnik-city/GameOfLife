#include <iostream>
#include <fstream>

#include "Memento.h"
#include "Board.h"

Board::Board(){}

Board::~Board(){}

Board::Board(const Board& oldBoard)
{
	m_board = oldBoard.GetBoard();
}

void Board::FillBoardFromFile(std::string pattern)
{
	std::string x;
	std::string y;
	char field;
	std::ifstream gameFile;
	gameFile.open(pattern, std::ios::in);
	if (gameFile.is_open())
	{
		std::string counter = "";
		int counted;
		std::vector<int> line;
		while (gameFile.get(field))
		{
			switch(field)
			{
			case '#':
				gameFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			case 'x':
				gameFile.ignore(std::numeric_limits<std::streamsize>::max(), '=');
				gameFile.get(field);
				gameFile.get(field);
				while (field != ',')
				{	
					x.push_back(field);
					gameFile.get(field);	
				}
				gameFile.get(field);
				gameFile.get(field);
				gameFile.ignore(std::numeric_limits<std::streamsize>::max(), '=');
				while (field != ',')
				{
					y.push_back(field);
					gameFile.get(field);
				}
				gameFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			case 'o':
				if (counter.empty())
					counter.append("1");
				counted = std::stoi(counter);
				for(auto i=0;i < counted;i++)
				{
					line.push_back(1);
				}
				counter = "";
				break;
			case 'b':
				if (counter.empty())
					counter.append("1");
				counted = std::stoi(counter);
				for (auto i = 0; i < counted; i++)
				{
					line.push_back(0);
				}
				counter = "";
				break;
			case '$':
				for (auto lenght = (line.size()); lenght < std::stoi(x); lenght++)
				{
					line.push_back(0);
				}
				m_board.push_back(line);
				line.clear();
				break;
			case '!':
				gameFile.ignore(std::numeric_limits<std::streamsize>::max(), EOF);
				break;
			default:
				counter.push_back(field);
			}
		}
	}
}

void Board::SaveBoardToFile(std::string pattern)
{
	std::ofstream gameFile;
	gameFile.open(pattern, std::ios::out);
	int prev, cur, counter = 0;
	if (gameFile.is_open())
	{
		gameFile << "#";
		gameFile << pattern;
		gameFile << "\n";
		gameFile << "x = " + std::to_string(SizeX());
		gameFile << ", y = " + std::to_string(SizeY());
		gameFile << ",\n";
		int count;
		for (int i = 0; i < SizeY(); i++)
		{
			for (int j = 0; j < (SizeX()-2); j++)
			{
				count = 1;
				while (j < SizeX() - 1 && m_board[i][j] == m_board[i][j + 1])
				{
					count++;
					j++;
				}
				if (count == SizeX() && m_board[i][j] == 0)
				{

				}
				else if (j == SizeX() - 1 && m_board[i][j] == 0)
				{

				}
				else
				{
					switch (m_board[i][j])
					{
					case 1:
						gameFile << std::to_string(count) + "o";
						break;
					case 0:
						gameFile << std::to_string(count) + "b";
					}
					
				}
			}
			gameFile << "$";
		}
		gameFile << "!";
	}
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

Memento *Board::createMemento() 
{
	return new Memento(*this);
}

void Board::restoreToMemento(Memento *memento) {

	*this = memento->getBoard();

}