#include<iostream>
using namespace std;
#pragma once
#include "CircularDoublyLinkedList.h"

//Abstract TopSpin Class

class TopSpinADT {
public:
	// shifts the pieces 1 to the left
	virtual void shiftLeft() = 0;
	//shifts the pieces 1 to the right
	virtual void shiftRight() = 0;
	//reverses the pieces in the spin mechanism
	virtual void spin() = 0;
	//Checks to see if the puzzle is solved
	virtual bool isSolved() = 0;
};

//TopSpin Class

class TopSpin :public TopSpinADT {
public:

	//TopSpin member functions and variables
	TopSpin(int size, int spinSize);
	~TopSpin();
	void shiftLeft();
	void shiftRight();
	void spin();
	bool isSolved();
	//Function to swap elements of the Linked List
	void swap(CircularDoublyLinkedList<int>::Iterator &firstt, CircularDoublyLinkedList<int>::Iterator &secondd);

	//Overwrite the ostream operator to make the output work
	//friend used to access the private members when required
	friend std::ostream& operator<< (std::ostream &os, TopSpin &ts) {
		os << "[ ";

		auto it = ts.start;

		for (int i = 0; i < ts.sizeOfSpin; i++, ++it)
		{
			os << it.getValue() << " ";
		}
		os << "] ";
		for (int i = ts.sizeOfSpin; i < ts.sizeOfBoard; i++, ++it)
		{
			os << it.getValue() << " ";
		}
		return os;
	}
public:
	void setBoardSize(int boardSize);
	int getBoardSize();
	void setSpinSize(int spinSize);
	int getSpinSize();
private:

	//Private member variables
	int sizeOfBoard;
	int sizeOfSpin;
	//CDLL object
	CircularDoublyLinkedList <int> List;
	//Iterator object 
	CircularDoublyLinkedList<int>::Iterator start;
	CircularDoublyLinkedList<int>::Iterator end;
};