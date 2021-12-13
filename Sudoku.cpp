#include "Sudoku.h"

Sudoku::Sudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			grid[i][j] = NULL;
		}
	}

}
void Sudoku::PrintBoard(int spaces[9][9]) {
	cout << "---------------------------" << endl;
	for (int i = 0; i < 9; i++) {
		cout << "|";
		for (int j = 0; j < 9; j++) {
			cout << spaces[i][j];
			cout << "|";
		}
		cout << "|";
	}
	cout << endl;
	cout << "| "<< spaces[0][0] << " |";
}
void Sudoku::getInput() {
	cout << "Enter Command" << endl;
	int setSpace1, setSpace2;
	int setVal;
	cin >> setSpace1 >> setSpace2 >> setVal;
	grid[setSpace1][setSpace2] = setVal;
}