#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <conio.h>
#include <fstream>
using namespace std;

struct sPlayer {
	string Name;
	int eWins;
	int nWins;
	int hWins;
};

class Sudoku {
	public:
		int grid[9][9];
		Sudoku();
		void PrintBoard(int spaces[9][9]);
		void getInput();
		bool checkWin(int spaces[9][9]);
};