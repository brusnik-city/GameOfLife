#pragma once
#include <vector>
#include "Board.h""
class Game
{
public:
	Game();
	~Game();
	void Run();
	void ReadFile();
	void PlayGame();
	void PrintBoard() const;
private:
	Board m_board;
};