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
	void PrintBoard() const;
	size_t Size() const;
	size_t SizeY() const;
	int& Value(int x, int y);
	std::vector<std::vector<int>>::iterator Begin();
	void SetValue(int x, int y, int value);
private:
	std::vector<std::vector<int>> m_board;
};