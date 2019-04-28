#pragma once
#include <vector>

class Board
{
public:
	Board();
	Board(const Board& oldBoard);
	~Board();
	std::vector<std::vector<int>> GetBoard() const;
	void FillBoardFromFile();
	size_t SizeX() const;
	size_t SizeY() const;
	int& Value(int x, int y);
	void SetValue(int x, int y, int value);
private:
	std::vector<std::vector<int>> m_board;
};