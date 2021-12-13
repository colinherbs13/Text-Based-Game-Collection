#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Player {
	string name;
	int playerNum;
	int wins;
};

class TicTacToe {
public:
	void Process();
	void ClearScreen() {
		cout << string(100, '\n');
	}
private:
	void Board(vector<Player> players, char spaces[9]);
	vector<Player> choosePlayers();
	int CheckWin(char spaces[9]);
	void Turn(int playerNum, string playerName, char spaces[9]);
	void CPUTurn(char spaces[9]);
	int minimax(char spaces[9], int depth, bool isMax);
};
