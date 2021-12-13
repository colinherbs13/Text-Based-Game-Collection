#include "TicTacToe.h"

void TicTacToe::Board(vector<Player> players, char spaces[9]) {
	if (players.size() == 1) {
		cout << "Player 1: " << players.at(0).name << "\tPlayer 2: CPU" << endl;
	}
	else {
		cout << "Player 1: " << players.at(0).name << "\tPlayer 2: " << players.at(1).name << endl;
	}
	cout << endl << endl << endl;
	cout << "      |        |      " << endl;
	cout << "  " << spaces[0] << "   |   " << spaces[1] << "    |  " << spaces[2] << "    " << endl;
	cout << "      |        |      " << endl;
	cout << "----------------------" << endl;
	cout << "      |        |      " << endl;
	cout << "  " << spaces[3] << "   |   " << spaces[4] << "    |  " << spaces[5] << "    " << endl;
	cout << "      |        |      " << endl;
	cout << "----------------------" << endl;
	cout << "      |        |      " << endl;
	cout << "  " << spaces[6] << "   |   " << spaces[7] << "    |  " << spaces[8] << "    " << endl;
	cout << "      |        |      " << endl;


}

vector<Player> TicTacToe::choosePlayers() {
	int playerCount = 0;
	vector<Player> newPlayers;
	// get number of players
	while ((playerCount != 1 && playerCount != 2)) {
		cout << "How many players?" << endl;
		cin >> playerCount;
		if ((playerCount != 1 && playerCount != 2)) {
			cout << "Invalid number of players!" << endl;
			playerCount = 0;
		}
	}
	for (int i = 0; i < playerCount; i++) {
		cout << "Enter Player " << i + 1 << " Name:" << endl;
		Player newPlayer;
		cin >> newPlayer.name;
		newPlayer.playerNum = i + 1;
		newPlayer.wins = 0;
		newPlayers.push_back(newPlayer);
	}
	return newPlayers;
}

int TicTacToe::CheckWin(char spaces[9]) {
	for (int i = 0; i < 9; i++) {
		if ((i == 0) || (i == 3) || (i == 6)) { //Check Rows Across 
			if ((spaces[i] == 'X') && (spaces[i + 1] == 'X') && (spaces[i + 2] == 'X')){
				return 1;
				break;
			}
			else if ((spaces[i] == 'O') && (spaces[i + 1] == 'O') && (spaces[i + 2] == 'O')) {
				return 2;
				break;
			}
		}
		if ((i == 0)) { //Check Right Diagonal
			if ((spaces[i] == 'X') && (spaces[4] == 'X') && (spaces[8] == 'X')) {
				return 1; 
				break;
			}
			else if ((spaces[i] == 'O') && (spaces[4] == 'O') && (spaces[8] == 'O')) {
				return 2;
				break;
			}
		}
		if ((i == 2)) { //Check Left Diagonal
			if ((spaces[i] == 'X') && (spaces[4] == 'X') && (spaces[6] == 'X')) {
				return 1;
				break;
			}
			else if ((spaces[i] == 'O') && (spaces[4] == 'O') && (spaces[6] == 'O')) {
				return 2;
				break;
			}
		}
		if ((i >= 0) && (i <= 2)) { //Check Columns
			if ((spaces[i] == 'X') && (spaces[i + 3] == 'X') && (spaces[i + 6] == 'X')) {
				return 1;
				break;
			}
			else if ((spaces[i] == 'O') && (spaces[i + 3] == 'O') && (spaces[i + 6] == 'O')) {
				return 2;
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (spaces[i] != 'X' && spaces[i] != 'O') {
			return 0;
		}
	}
	return 3;
}

void TicTacToe::Turn(int playerNum, string playerName, char spaces[]) {
	int spaceNum;
	cout << playerName << "'s Turn!" << endl;
	cin >> spaceNum;
	if (spaceNum >= 1 && spaceNum <= 9) {
		if ((playerNum == 1) && (spaces[spaceNum - 1] != 'X') && (spaces[spaceNum - 1] != 'O')) {
			spaces[spaceNum - 1] = 'X';
		}
		else if ((playerNum == 2) && (spaces[spaceNum - 1] != 'X') && (spaces[spaceNum - 1] != 'O')) {
			spaces[spaceNum - 1] = 'O';
		}
		else {
			Turn(playerNum, playerName, spaces);
		}
	}
}

int TicTacToe::minimax(char spaces[9], int depth, bool isMax) {
	int result = CheckWin(spaces);
	int scores;
	if (result != 0) {
		if (result == 2) {
			scores = 10;
		}
		else if (result == 1) {
			scores = -10;
		}
		else if (result == 3) {
			scores = 0;
		}
		return scores;
	}
	if (isMax) {
		int bestScore = -1000;
		for (int i = 0; i < 9; i++) {
			if (spaces[i] != 'X' && spaces[i] != 'O') {
				char temp = spaces[i];
				spaces[i] = 'O';
				int score = minimax(spaces, depth + 1, false);
				spaces[i] = temp;
				bestScore = max(score, bestScore);
			}
		}
		return bestScore;
	}
	else {
		int bestScore = 1000;
		for (int i = 0; i < 9; i++) {
			if (spaces[i] != 'X' && spaces[i] != 'O') {
				char temp = spaces[i];
				spaces[i] = 'X';
				int score = minimax(spaces, depth + 1, true);
				spaces[i] = temp;
				bestScore = min(score, bestScore);
			}
		}
		return bestScore;
	}
}

void TicTacToe::CPUTurn(char spaces[]) {
	int bestScore = -1000;
	int move;
	for (int i = 0; i < 9; i++) {
		if (spaces[i] != 'X' && spaces[i] != 'O') {
			char temp = spaces[i];
			spaces[i] = 'O';
			int score = minimax(spaces, 0, false);
			spaces[i] = temp;
			if (score > bestScore) {
				bestScore = score;
				move = i;
			}
		}
	}
	spaces[move] = 'O';
}

void TicTacToe::Process() {
	char spaces[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int turnCount = 0;
	vector<Player> players;
	players = choosePlayers();
	system("CLS");
	if (players.size() == 2) {
		while (1) {
			Board(players, spaces);
			turnCount++;
			if ((turnCount % 2) == 0) {
				Turn(2, players.at(1).name, spaces);
			}
			else {
				Turn(1, players.at(0).name, spaces);
			}
			if (CheckWin(spaces) == 1) {
				Board(players, spaces);
				cout << players.at(0).name << " WINS!!!" << endl;
				players.at(0).wins += 1;
				break;
			}
			else if (CheckWin(spaces) == 2) {
				Board(players, spaces);
				cout << players.at(1).name << "WINS!!!" << endl;
				players.at(1).wins += 1;
				break;
			}
		}
	}
	
	else if (players.size() == 1) {
		while (1) {
			Board(players, spaces);
			turnCount++;
			if ((turnCount % 2) == 0) {
				CPUTurn(spaces);
			}
			else {
				Turn(1, players.at(0).name, spaces);
			}
			if (CheckWin(spaces) == 1) {
				Board(players, spaces);
				cout << players.at(0).name << " WINS!!!" << endl;
				players.at(0).wins += 1;
				break;
			}
			else if (CheckWin(spaces) == 2) {
				Board(players, spaces);
				cout << "YOU LOSE!!!!" << endl;
				break;
			}
			else if (CheckWin(spaces) == 3) {
				Board(players, spaces);
				cout << "It's a Tie!!" << endl;
				break;
			}
		}
	}
}