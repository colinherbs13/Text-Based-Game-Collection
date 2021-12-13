#include <iostream>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include "TicTacToe.h"
#include "Sudoku.h"
using namespace std;

int main(void) {
	char gameChoice;
	while (1) {
		cout << "\t\t    ~Choose a Game~" << endl;
		cout << "1) TicTacToe \t 2) Sudoku \t 3) Chutes and Ladders" << endl;
		cout << "Q) Quit" << endl;
		cin >> gameChoice;
		switch (gameChoice) {
		case '1':
		{
			system("CLS");
			TicTacToe newGame;
			newGame.Process();
		}
			break;
		case '2':
		{
			system("CLS");
			Sudoku sGame;
			sGame.getInput();
			sGame.PrintBoard(sGame.grid);
		}	
			break;
		case '3':
			system("CLS");
			break;
		case 'Q':
			return 0;
			break;
			break;
		case 'q':
			return 0;
			break;
		}

	}
	return 0;
}


