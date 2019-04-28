#pragma once
#include <deque>

class Memento;

class Caretaker {

public:
	Caretaker();
	~Caretaker();
	void setMemento(Memento *memento);
	Memento *getMementoBackward();
	Memento *getMementoForward();

private:
	std::deque<Memento *> _listMemento;
	int position = -1;

};