#pragma once

#include "Memento.h"
#include "Board.h"


class Memento 
{
	friend class Board;
public:
	~Memento();
private:

	Memento(Board board);
	void setBoard(Board board);
	Board getBoard();

	Board m_board;


};