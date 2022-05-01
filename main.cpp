#include<iostream>
#include "CircularDoublyLinkedList.h"
#include "TopSpin.h"
#include <ctime>
#include <cstdlib>
#include<limits>
#include<chrono>

using namespace std;

//RandomizePuzzle with a random number of moves, calls both ShiftLeft and Spin functions
void randomizePuzzle(int numbOfMoves, TopSpin &TopSpinObj1) {
	for (int i = 0; i < numbOfMoves; i++)
	{
		int random = (rand() % 15) + 1;
		for (int j = 0; j < random; j++)
		{
			TopSpinObj1.shiftLeft();
		}
		TopSpinObj1.spin();
	}
}


int main()
{
	//This part is for the instructions of the game.

	cout << "                                             Welcome to our game       " << endl << endl;
	cout << "If you want to read the instructions Enter #1, If not enter any other number. \n";
	int inst;
	while (!(cin >> inst)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "you have to enter a number \n";
		cout << endl;
	}
	if (inst == 1)
	{ 
		cout << "*************\n";
		cout << "To win the game you must form a sequence of numbers ascendingly by shifting and spinning the list\n";
		cout << "Note that the shifting operation shiifts the numbers not the squared bracket \n";
		cout << "For example form [7 8 9 10 1 2 3 4 5 6] \n";
		cout << "Or form [1 2 3 4 5 6 7 8 9 10] to win \n ";
		cout << "Your health is given according to the difficulty choosen \n";
		cout << "Easy : 100" << endl;
		cout << "Normal : 60" << endl;
		cout << "Hard : 50" << endl;
		cout << "Extreme : 9999" << endl;
		cout << "Each spin will decrease your health 5 points and the shift decrease by amount of shift \n";
	}

	//This part is for choosing the difficulty of the game.

	cout << "*************\n";
	cout << "Choose game difficulty \n";
	cout << "1 - Easy \n";
	cout << "2 - Normal \n";
	cout << "3 - Hard \n";
	cout << "4 - Extreme \n";
	cout << "*************\n";
	int difficulty , size_diff , spin_diff,Health;
	int countshifts = 0, countspin = 0;
	choose_dificulty:
    // this while loop to check if the input is not a number.

	while (!(cin >> difficulty)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "you have to enter a number from 1 to 4 \n";
		cout << endl;
	}
	cout << endl << "---------------------------------------" << endl;

	//The following part sets the game specifications

 	if (difficulty == 1)
	{
		Health = 100;
		size_diff = 8;
		spin_diff = 2;
	}
	else if (difficulty == 2)
	{
		Health = 60;
		size_diff = 9;
		spin_diff = 3;
	}
	else if (difficulty == 3)
	{
		Health = 50;
		size_diff = 15;
		spin_diff = 3;
	}
	else if (difficulty == 4)
	{
		Health = 9999;
		size_diff = 20;
		spin_diff = 4;
	}
	else
	{
		cout << "Enter number corresponding to the dificulty \n";
		goto choose_dificulty; 
	}
	//Create TopSpin object

	TopSpin TopSpinObject(size_diff,spin_diff);

	srand(time(NULL));

	//Number of moves to initalize the puzzle with

	int numOfMoves=rand()%20;


	//Created a function to randomize the puzzle with a random number of shiftLeft function calls and a spin

	randomizePuzzle(numOfMoves, TopSpinObject);

	//Prints the object through the overloaded ostream operator

	cout << TopSpinObject << endl;



	//While loop that runs till the user selects Quit or Wins the game
	while (true)
	{
		cout << endl<<"Your health is : " << Health <<"          "<< endl;
		cout << "---------------------------------------" << endl;
		cout << endl << "Please choose from the following options enter your choice by entering the corresponding " <<
			"number: " << endl;
		cout << endl << "1. Shift" << endl << "2. Spin" << endl << "3. Quit" << endl;
		int optionNumber;
		cout << endl << "Your choice: ";
		while (!(cin >> optionNumber)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "you have to enter a number from 1 to 3 \n";
			cout << endl;
		}
		cout << endl;
		cout << "---------------------------------------" << endl;

		//Switch statement for the user options to Shift, Spin or Quit
		switch (optionNumber)
		{
		case 1:
		{
			int numOfShifts;
			cout << "Enter number of shifts: ";
			while (!(cin >> numOfShifts)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "you have to enter a number \n";
				cout << endl;
			}
			countshifts += 1;
			Wrong_shift :
			cout << endl << "1. Shift right\n";
			cout << "2. Shift left\n";
			cout << endl << "Your choice: ";
			int shiftOption;
			while (!(cin >> shiftOption)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "you have to enter a number from 1 and 2 \n";
				cout << endl;
			}
			if (shiftOption != 1 && shiftOption != 2)
				goto Wrong_shift;

			cout << "---------------------------------------" << endl;
			cout << endl;
			//Decreasing the value of health.  

			Health -= numOfShifts;
			//Nested switch statement for user options to Shift Left or Shift Right
			switch (shiftOption)
			{
			case 1:
			{
				auto start = chrono::high_resolution_clock::now();//start counting time 
				for (int i = 0; i < numOfShifts; i++)
				{
					TopSpinObject.shiftRight();
				}
				auto end = chrono::high_resolution_clock::now();//end of counting time
				auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();//difference betwen time of start and end
				cout << "time taken =  " << duration << "  nano seconds" << endl;

				break;
			}
			case 2:
			{
				auto start = chrono::high_resolution_clock::now();//start counting time 
				for (int i = 0; i < numOfShifts; i++)
				{
					TopSpinObject.shiftLeft();
				}
				auto end = chrono::high_resolution_clock::now();//end of counting time
				auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();//difference betwen time of start and end
				cout << "time taken =  " << duration << "  nano seconds" << endl;
				break;
			}
			}
			break;
		}
		case 2:
		{		auto start = chrono::high_resolution_clock::now();//start counting time 
		TopSpinObject.spin();
		Health -= 5;
		countspin += 1;
		auto end = chrono::high_resolution_clock::now();//end of counting time
		auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();//difference betwen time of start and end
		cout << "time taken =  " << duration << "  nano seconds" << endl;
			
			break;
		}
		case 3:
		{
			return 0;
		}
		}

		cout << TopSpinObject << endl;

		//If statement that continuously checks if the puzzle is solved
		if (TopSpinObject.isSolved())
		{
			cout << endl << "Your health is : " << Health << "          " << endl;
			cout << "Congratulations! You solved the puzzle. \n";
			cout << "the total number of shifts you use is " << countshifts << endl;
			cout << "and the total number of spins you use is " << countspin << endl;

			break;
			return 0;
		}
		//If your health reached zero , you lost

		if (TopSpinObject.isSolved()!=1 && Health<=0)
		{
			cout << "Bad luck...Try again \n";
			cout << "the total number of shifts you use is " << countshifts << endl;
			cout << "and the total number of spins you use is " << countspin << endl;
			break;
			return 0;
		}

	} //While loop ends here

	return 0;
}