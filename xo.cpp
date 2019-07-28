#include <iostream>
//#include <random> 
#include <iomanip>
#include <algorithm>
#define O 'O';
#define X 'O';
using namespace std;
// -------
// |1|2|3|
// -------
// |4|5|6|
// -------
// |7|8|9|
// -------
void moves(char game[3][3],char move,int inputPlayerMove,bool* CheckForMultipleX, bool* CheckForMultipleO,int*NumberOfMoves);
void createLayout(char game[3][3]);
void maintence(char* move);
int win(char game[3][3]);
int main()
{

	char game[][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
	int NumberOfMoves = 0; // numberOfMoves
	char move = 'X';
	bool CheckForMultipleX = false; // change it to a varuble name
	bool CheckForMultipleO = false; // change it to a varuble name
	// an array with 5 rows and 2 columns.
	int inputPlayerMove = -1; // x starts
	string cpup2; // inputPlayerMode , create enum gameMode {CPU, 2 players}
	cout << "Would you like to play cpu or 2p " << endl;
	cin >> cpup2;
	if (cpup2 == "2p") {
		createLayout(game);
		while(NumberOfMoves < 9){
			cout << "Enter the number you'd like to put on" << endl;
			cin >> inputPlayerMove;
			moves(game, move, inputPlayerMove,&CheckForMultipleX,&CheckForMultipleO,&NumberOfMoves);
			 if(CheckForMultipleX == true) {
				move = 'O';
			}
			else if(CheckForMultipleO == true) {
				move = 'X';
			}
			
			else {
				maintence(&move);
			}
			createLayout(game);
			win(game);
			if (NumberOfMoves == 9) {
				cout << "It's a Draw!" << endl;
			}
		}
	}
	else if (cpup2 == "cpu") {
		// TD ai
	}
}
void createLayout(char game[3][3]) {
	cout << "-------" << endl;
	for (int i = 0; i < 3; i++) {
		cout << '|';
		for (int j = 0; j < 3; j++) {
			cout << game[i][j];
			cout << '|';
			if (j == 2) {
				cout << endl;
				cout << "-------" << endl;
			}
		}

	}

}
void maintence(char* move) {
	if (*move == 'X') {
		*move = 'O';
	}
	else {
		*move = 'X';
	}
}

// check for comments
void moves(char game[3][3],char move, int inputPlayerMove,bool *CheckForMultipleX,bool *CheckForMultipleO,int*NumberOfMoves) {
	
	// create a function if the input is valid
	// create a function that excute the move if valid
	for (int i = 0; i <= 9; i++) {
		if (inputPlayerMove == i) {
			for (int x = 0; x < 3; x++) {
				for (int j = 0; j < 3; j++) {
					if (game[x][j] == 'X') {
						cout << "You already used this place! Pleaes choose a diffrent position." << endl;
						*CheckForMultipleX = true;
					}
					else if (game[x][j] == 'O') {
						cout << "You already used this place! Pleaes choose a diffrent position." << endl;
						*CheckForMultipleO = true;
					}
					else {
						*CheckForMultipleO = false;
						*CheckForMultipleX = false;
						game[x][j] = move;
						*NumberOfMoves = *NumberOfMoves + 1;
					}
				}
			}
		}
	}
	
}

// rename
int win(char game[3][3]) {
	bool winorno = false;
	int countt = 0;
	for (int i = 0; i < 3; i++) {
		if (game[0][i] == 'X' && game[1][i] == 'X' && game[2][i] == 'X') {
			cout<< "X won!" << endl;
			winorno = true;
			exit(EXIT_FAILURE);
		}
		if (game[0][i] == 'O' && game[1][i] == 'O' && game[2][i] == 'O') {
			cout << "O won!" << endl;
			winorno = true;
			exit(EXIT_FAILURE);
		}
	}
	for (int i = 0; i < 3; i++) {
		if (game[i][0] == 'X' && game[i][1] == 'X' && game[i][2] == 'X') {
			cout << "X won!" << endl;
			winorno = true;
			exit(EXIT_FAILURE);
		}
		if (game[i][0] == 'O' && game[i][1] == 'O' && game[i][2] == 'O') {
			cout << "O won!" << endl;
			winorno = true;
			exit(EXIT_FAILURE);
		}
	}
	if (game[0][0] == 'X' && game[1][1] == 'X' && game[2][2] == 'X') {
		cout << "X won!" << endl;
		winorno = true;
		exit(EXIT_FAILURE);
	}
	if (game[0][2] == 'X' && game[1][1] == 'X' && game[2][0] == 'X') {
		cout << "X won!" << endl;
		winorno = true;
		exit(EXIT_FAILURE);
	}
	if (game[0][2] == 'O' && game[1][1] == 'O' && game[2][0] == 'O') {
		cout << "O won!" << endl;
		winorno = true;
		exit(EXIT_FAILURE);
	}
	if (game[0][0] == 'O' && game[1][1] == 'O' && game[2][2] == 'O') {
		cout << "O won!" << endl;
		winorno = true;
		exit(EXIT_FAILURE);
	}
}
