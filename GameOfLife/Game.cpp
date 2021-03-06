#include <iostream>
#include <fstream>
#include <string>

#include "Game.h"

Game::Game(std::string pattern) 
{
	m_board.FillBoardFromFile(pattern);
}

Game::~Game() {}

void Game::PlayGame(int begin, int end)
{
	int counter = 0;
	Board newBoard = m_board;
	for (int i = begin; i < end; i++)
	{
		for (int j = 0; j < m_board.SizeY(); j++)
		{
			if (i == 0 )
			{
				if (j == 0)
				{
					if (m_board.Value(m_board.SizeX()-1, m_board.SizeY()-1) == 1) counter++;
					if (m_board.Value(m_board.SizeX()-1, j) == 1) counter++;
					if (m_board.Value(m_board.SizeX()-1, j + 1) == 1) counter++;
					if (m_board.Value(i, m_board.SizeY()-1) == 1) counter++;
					if (m_board.Value(i, j + 1) == 1) counter++;
					if (m_board.Value(i + 1, m_board.SizeY()-1) == 1) counter++;
					if (m_board.Value(i + 1, j) == 1) counter++;
					if (m_board.Value(i + 1, j + 1) == 1) counter++;

				}
				else if (j + 1 == m_board.SizeY())
				{
					if (m_board.Value(m_board.SizeX()-1, j - 1) == 1) counter++;
					if (m_board.Value(m_board.SizeX()-1, j) == 1) counter++;
					if (m_board.Value(m_board.SizeX()-1, 0) == 1) counter++;
					if (m_board.Value(i, j - 1) == 1) counter++;
					if (m_board.Value(i, 0) == 1) counter++;
					if (m_board.Value(i + 1, j - 1) == 1) counter++;
					if (m_board.Value(i + 1, j) == 1) counter++;
					if (m_board.Value(i + 1, 0) == 1) counter++;
				}
				else
				{
					if (m_board.Value(m_board.SizeX()-1, j - 1) == 1) counter++;
					if (m_board.Value(m_board.SizeX()-1, j) == 1) counter++;
					if (m_board.Value(m_board.SizeX()-1, j + 1) == 1) counter++;
					if (m_board.Value(i, j - 1) == 1) counter++;
					if (m_board.Value(i, j + 1) == 1) counter++;
					if (m_board.Value(i + 1, j - 1) == 1) counter++;
					if (m_board.Value(i + 1, j) == 1) counter++;
					if (m_board.Value(i + 1, j + 1) == 1) counter++;
				}

			}
			else if (i + 1 == m_board.SizeX())
			{
				if (j == 0)
				{
					if (m_board.Value(i - 1, m_board.SizeY()-1) == 1) counter++;
					if (m_board.Value(i - 1, j) == 1) counter++;
					if (m_board.Value(i - 1, j + 1) == 1) counter++;
					if (m_board.Value(i, m_board.SizeY()-1) == 1) counter++;
					if (m_board.Value(i, j + 1) == 1) counter++;
					if (m_board.Value(0, m_board.SizeY()-1) == 1) counter++;
					if (m_board.Value(0, j) == 1) counter++;
					if (m_board.Value(0, j + 1) == 1) counter++;
				}
				else if (j + 1 == m_board.SizeY())
				{
					if (m_board.Value(i - 1, j - 1) == 1) counter++;
					if (m_board.Value(i - 1, j) == 1) counter++;
					if (m_board.Value(i - 1, 0) == 1) counter++;
					if (m_board.Value(i, j - 1) == 1) counter++;
					if (m_board.Value(i, 0) == 1) counter++;
					if (m_board.Value(0, j - 1) == 1) counter++;
					if (m_board.Value(0, j) == 1) counter++;
					if (m_board.Value(0, 0) == 1) counter++;
				}
				else
				{
					if (m_board.Value(i - 1, j - 1) == 1) counter++;
					if (m_board.Value(i - 1, j) == 1) counter++;
					if (m_board.Value(i - 1, j + 1) == 1) counter++;
					if (m_board.Value(i, j - 1) == 1) counter++;
					if (m_board.Value(i, j + 1) == 1) counter++;
					if (m_board.Value(0, j - 1) == 1) counter++;
					if (m_board.Value(0, j) == 1) counter++;
					if (m_board.Value(0, j + 1) == 1) counter++;
				}
				
			}
			else if (j == 0)
			{
				if (m_board.Value(i - 1, m_board.SizeY()-1) == 1) counter++;
				if (m_board.Value(i - 1, j) == 1) counter++;
				if (m_board.Value(i - 1, j + 1) == 1) counter++;
				if (m_board.Value(i, m_board.SizeY()-1) == 1) counter++;
				if (m_board.Value(i, j + 1) == 1) counter++;
				if (m_board.Value(i + 1, m_board.SizeY()-1) == 1) counter++;
				if (m_board.Value(i + 1, j) == 1) counter++;
				if (m_board.Value(i + 1, j + 1) == 1) counter++;
			}
			else if (j + 1 == m_board.SizeY())
			{
				if (m_board.Value(i - 1, j - 1) == 1) counter++;
				if (m_board.Value(i - 1, j) == 1) counter++;
				if (m_board.Value(i - 1, 0) == 1) counter++;
				if (m_board.Value(i, j - 1) == 1) counter++;
				if (m_board.Value(i, 0) == 1) counter++;
				if (m_board.Value(i + 1, j - 1) == 1) counter++;
				if (m_board.Value(i + 1, j) == 1) counter++;
				if (m_board.Value(i + 1, 0) == 1) counter++;
			}
			else
			{
				if (m_board.Value(i - 1, j - 1) == 1) counter++;
				if (m_board.Value(i - 1, j) == 1) counter++;
				if (m_board.Value(i - 1, j + 1) == 1) counter++;
				if (m_board.Value(i, j - 1) == 1) counter++;
				if (m_board.Value(i, j + 1) == 1) counter++;
				if (m_board.Value(i + 1, j - 1) == 1) counter++;
				if (m_board.Value(i + 1, j) == 1) counter++;
				if (m_board.Value(i + 1, j + 1) == 1) counter++;
			}
			if (m_board.Value(i, j) == 0 && counter == 3)
				newBoard.SetValue(i, j, 1);
			else if (m_board.Value(i, j) == 1 && (counter == 2 || counter == 3))
				newBoard.SetValue(i, j, 1);
			else
				newBoard.SetValue(i, j, 0);
			counter = 0;
		}
	}
	m_caretaker.setMemento(m_board.createMemento());
	//m_board = newBoard;
	for (int i = begin; i < end; i++)
	{
		for (int j = 0; j < m_board.SizeY(); j++)
		{
			m_board.Value(i,j) = newBoard.Value(i,j);
		}
	}
}


size_t Game::GetSizeX() const
{
	return m_board.SizeX();
}

size_t Game::GetSizeY() const
{
	return m_board.SizeY();
}

bool Game::GetCell(int i, int j)
{
	return  m_board.Value(i, j);
}

void Game::BackwardRestoreBoardToMemento()
{
	m_board.restoreToMemento(m_caretaker.getMementoBackward());
}

void Game::ForwardRestoreBoardToMemento()
{
	m_board.restoreToMemento(m_caretaker.getMementoForward());
}

void Game::SavePattern(std::string pattern)
{
	m_board.SaveBoardToFile(pattern);
}

