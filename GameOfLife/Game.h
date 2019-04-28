#pragma once
#include <vector>

#include "Board.h"
class Game
{
public:
	Game();
	~Game();
	void PlayGame();
	size_t GetSizeX() const;
	size_t GetSizeY() const;
	bool GetCell(int i, int j);
private:
	Board m_board;
};