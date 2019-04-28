#include <iostream>
#include "Caretaker.h"
#include "Memento.h"

Caretaker::Caretaker(){}

Caretaker::~Caretaker() 
{
	for (Memento *element : _listMemento)
		delete element;

	_listMemento.clear();
}

void Caretaker::setMemento(Memento *memento) 
{
	_listMemento.push_back(memento);
	position = _listMemento.size();
}

Memento *Caretaker::getMementoBackward() 
{

	if (position > 0)
		position--;

	return _listMemento[position];
}

Memento *Caretaker::getMementoForward()
{

	if (position < _listMemento.size() - 1)
		position++;

	return _listMemento[position];
}