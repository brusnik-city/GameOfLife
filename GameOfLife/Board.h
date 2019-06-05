#pragma once
#include <vector>
#include <string>

class Memento;

class Board
{
public:
	Board();
	Board(const Board& oldBoard);
	~Board();
	std::vector<std::vector<int>> GetBoard() const;
	void FillBoardFromFile(std::string pattern);
	void SaveBoardToFile(std::string pattern);
	size_t SizeX() const;
	size_t SizeY() const;
	int& Value(int x, int y);
	void SetValue(int x, int y, int value);
	Memento *createMemento();
	void restoreToMemento(Memento *memento);
private:
	std::vector<std::vector<int>> m_board;
};