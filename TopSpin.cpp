#include<iostream>
#include "TopSpin.h"

using namespace std;

//To shift left one spot
void TopSpin::shiftLeft()
{
	++start;
	++end;
}

//To shift right one spot
void TopSpin::shiftRight()
{
	--start;
	--end;
}

//Boolean function to check if the board is solved
bool TopSpin::isSolved()
{
	

	bool win = false;
	CircularDoublyLinkedList<int>::Iterator it = start;
	
	while (it.getValue() != 1)
		++it;
	
	for (int i = 1; i <= sizeOfBoard; i++)
	{
		if (i == it.getValue())
		{
			win = true;
		}
		else
		{
			win = false;
			break;
		}
		++it;
	}
	//If-Else to return boolean
	if (win == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//TopSpin constructor, adds data to the nodes
TopSpin::TopSpin(int size , int spinSize)
{
	sizeOfBoard = size;
	sizeOfSpin = spinSize;
	if (sizeOfBoard >= 1 && sizeOfSpin <= sizeOfBoard)
	{
		for (int i = 1; i <= sizeOfBoard; i++)
		{
			List.addNode(i);
		}
	}
	start = List.begin();
	end = List.end();
}

//CDLL Spin function

void TopSpin::spin()
{
	using Iterator = CircularDoublyLinkedList<int>::Iterator;
	Iterator first = start;
	Iterator second = start;

	//To keep track of the start and end nodes

	for (int i = 0; i < getSpinSize() - 1; i++)
	{
		++second;
	}

	//For loop for the swap of pairs of firsts and seconds

	for (int i = 0; i < getSpinSize() / 2; i++)
	{
		swap(first, second);

		++first;
		--second;
	}

}

//Swap function using iterators, called from spin function
void TopSpin::swap(CircularDoublyLinkedList<int>::Iterator &Tfirst, CircularDoublyLinkedList<int>::Iterator &Tsecond)
{
	int temp = Tfirst.getValue();
	Tfirst.setValue(Tsecond.getValue());
	Tsecond.setValue(temp);
}

//TopSpin destructor
TopSpin::~TopSpin() {}

//Getters and setters for spin size and board size
int TopSpin::getBoardSize()
{
	return sizeOfBoard;
}

void TopSpin::setBoardSize(int boardSize)
{
	sizeOfBoard = boardSize;
}

int TopSpin::getSpinSize()
{
	return sizeOfSpin;
}

void TopSpin::setSpinSize(int spinSize)
{
	sizeOfSpin = spinSize;
}