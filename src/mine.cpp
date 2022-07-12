#include "include/mine.h"
#include <ctime>
#include <iostream>

using namespace std;

bool MineField::checkPosition(int pos1, int pos2)
{
	if (gameBoard[pos1][pos2] == '#')
		return true;

	return false;
}

bool MineField::checkPositionGameBoard(int pos1, int pos2)
{
	if (gameBoard[pos1][pos2] == '#');
}

/** Set the mines in the gameBoard
 * @mines: number of mines
 * **/
void MineField::initGameBoard(int mines)
{
	srand( time(nullptr) );

	while(mines) {
		int i = rand() % N;
		int j = rand() % M;

		if (gameBoard[i][j] == '#') {
			gameBoard[i][j] = 'x';
			mines--;
		}
	}

	numbersBoard();
}


void MineField::initGame(int mines)
{

	for (int i=0; i < N; i ++)
		for (int j=0; j < M; j++) {
			gameBoard[i][j] = '#';
			_printBoard[i][j] = '#';
			flagBoard[i][j] = '#';
			picked[i][j] = false;
		}

	initGameBoard(mines);
}


void MineField::printBoard(void)
{
	int i;
	int j;

	for (i=0; i < N; i ++) {
		for (j=0; j < M; j++) {
			cout << gameBoard[i][j];
		}
		cout << "\n";
		j = 0;
	}

	for (i=0; i < N; i ++) {
		for (j=0; j < M; j++) {
			cout << _printBoard[i][j];
		}
		cout << "\n";
		j = 0;
	}
}

// TODO: turn that a recursive function instead O(n^2)
void MineField::numbersBoard(void)
{
	int i;
	int j;
	int _count = 0;

	for (i = 0; i < N; i++) {
		for(j = 0; j < M; j++ ){
			if (gameBoard[i][j] == 'x')
				continue;
			else {
				// behind
				if(((j - 1) >= 0) && gameBoard[i][j-1] == 'x')
					_count++;
				// front
				if (((j + 1) < M) && gameBoard[i][j+1] == 'x')
					_count++;
				// up
				if (((i - 1) >= 0) && gameBoard[i-1][j] == 'x')
					_count++;
				// up behind
				if ((((i - 1) >= 0 && ((j - 1) >= 0)) &&
							gameBoard[i-1][j-1] ==
							'x'))
					_count++;
				// up front
				if (((i - 1) >= 0 && ((j+1) < M)) &&
						gameBoard[i-1][j+1] == 'x')
					_count++;
				// down
				if (((i + 1) < N) && gameBoard[i+1][j] == 'x')
					_count++;
				// down behind
				if (((i + 1 < N) && (j - 1 >= 0) &&
							gameBoard[i+1][j-1] ==
							'x'))
					_count++;
				// down front
				if ((((i + 1) < N) && (j + 1) < M) &&
					gameBoard[i+1][j+1] == 'x')
					_count++;
			}
			gameBoard[i][j] = _count + '0';
			_count = 0;
		}
	}
}

/** turn a position when it is picked
 *
 **/
void MineField::turnPos(int i, int j)
{
	if (!picked[i][j]) {
		picked[i][j] = true;
		_printBoard[i][j] = gameBoard[i][j];
	}

}

/** Turn all zero nearby
 * @iI index of the column
 * @iJ index of the line
 **/
void MineField::zeroTurn(int iI, int iJ)
{
	string sI = to_string(iI);
	string sJ = to_string(iJ);
	string key = sI + sJ;

	// turn it always when zero
	turnPos(iI, iJ);
	if (visitedMap.find(key) == visitedMap.end()) {
		visitedMap.insert( std::pair<string,bool>(key, true));

		// behind
		if((iJ - 1) >= 0) {
			if (gameBoard[iI][iJ-1] != '0')
				turnPos(iI, iJ-1);
			else
				zeroTurn(iI, iJ - 1);
		}
		// front
		if ((iJ + 1) < M) {
			if (gameBoard[iI][iJ+1] != '0')
				turnPos(iI, iJ + 1);
			else
				zeroTurn(iI, iJ + 1);
		}
		// up
		if ((iI - 1) >= 0) {
		       if (gameBoard[iI-1][iJ] != '0')
				turnPos(iI - 1, iJ);
		       else
			       	zeroTurn(iI - 1, iJ);
		}
		// up behiInd
		if (((iI - 1) >= 0 && ((iJ - 1) >= 0))) {
			if (gameBoard[iI-1][iJ-1] !=  '0')
				turnPos(iI - 1, iJ - 1);
			else
				zeroTurn(iI - 1, iJ - 1);
		}
		// up front
		if ((iI - 1) >= 0 && ((iJ+1) < M)) {
			if (gameBoard[iI-1][iJ+1] != '0')
				turnPos(iI - 1, iJ + 1);
			else
				zeroTurn(iI - 1, iJ + 1);
		}
		// down
		if ((iI + 1) < N) {
			if (gameBoard[iI+1][iJ] != '0')
				turnPos(iI + 1, iJ);
			else
				zeroTurn(iI + 1, iJ);
		}
		// down behiInd
		if ((iI + 1 < N) && (iJ - 1 >= 0)) {
			if (gameBoard[iI+1][iJ-1] != '0')
				turnPos(iI + 1, iJ - 1);
			else
				zeroTurn(iI + 1, iJ - 1);
		}
		// down front
		if (((iI + 1) < N) && (iJ + 1) < M) {
			if (gameBoard[iI+1][iJ+1] != '0')
				turnPos(iI + 1, iJ + 1);
			else
				zeroTurn(iI + 1, iJ + 1);
		}
	}
}

void MineField::menuGame(void)
{
	int Y;
	int X;
	char quit;

	cout << "========== MineField ==========" << endl;
	cout << endl;
	cout << "Exit ? [y/n]" << endl;
	cin >> quit;
	cout << "Pick a position in the MineField " << N << " x " << M << endl;
	cout << "Pick X coord (0 - 49): ";
	cin >> X;
	cout << "Pick Y coord (0 - 49): ";
	cin >> Y;

	if (gameBoard[X][Y] == '0') zeroTurn(X,Y);
	else turnPos(X, Y);
	printBoard();
}
