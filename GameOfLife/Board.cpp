#include <iostream>
#include <fstream>
#include <string>

#include "Memento.h"
#include "Board.h"

Board::Board(){}

Board::~Board(){}

Board::Board(const Board& oldBoard)
{
	m_board = oldBoard.GetBoard();
}

void Board::FillBoardFromFile()
{
	std::string x;
	std::string y;
	char field;
	std::ifstream gameFile;
	gameFile.open("Glider.rle", std::ios::in);
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
				for (int i = 0; i < std::stoi(x)+2; i++)
					line.push_back(0);
				m_board.push_back(line);
				line.clear();
				line.push_back(0);
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
				for (auto lenght = (line.size()); lenght < std::stoi(x)+2; lenght++)
				{
					line.push_back(0);
				}
				m_board.push_back(line);
				line.clear();
				line.push_back(0);
				break;
			case '!':
				for (auto lenght = (line.size()); lenght < std::stoi(x)+2; lenght++)
				{
					line.push_back(0);
				}
				line.push_back(0);
				m_board.push_back(line);
				line.clear();
				for (int i = 0; i < std::stoi(x) + 2; i++)
					line.push_back(0);
				m_board.push_back(line);
				gameFile.ignore(std::numeric_limits<std::streamsize>::max(), EOF);
				break;
			default:
				counter.push_back(field);
			}
		}
	}

	/*{
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
		std::cout << "nie otworzono";*/
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