#pragma once
#include <vector>

#include "Board.h"
#include "Caretaker.h"
class Game
{
public:
	Game();
	~Game();
	void PlayGame();
	size_t GetSizeX() const;
	size_t GetSizeY() const;
	bool GetCell(int i, int j);
	void BackwardRestoreBoardToMemento();
	void ForwardRestoreBoardToMemento();
private:
	Board m_board;
	Caretaker m_caretaker;
};