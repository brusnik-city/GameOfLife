#include <iostream>
#include "Memento.h"

Memento::Memento(Board board) : m_board(board) {}

Memento::~Memento() {}

void Memento::setBoard(Board board) 
{
	m_board = board;
}

Board Memento::getBoard() 
{
	return m_board;
}
