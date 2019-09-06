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
			virado[i][j] = false;
		}

	initGameBoard(mines);
}


void MineField::printBoard(void)
{
	int i;
	int j;

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

void MineField::turnPos(int i, int j)
{
	if (!virado[i][j]) {
		virado[i][j] = true;
		_printBoard[i][j] = gameBoard[i][j];
	}

}

void MineField::zeroTurn(int iI, int iJ)
{
	string sI = to_string(iI);
	string sJ = to_string(iJ);
	string key = sI + sJ;

	; // vira - sempre q zero ja vira
	if (visitedMap.find(key) == visitedMap.end()) {
		visitedMap.insert( std::pair<string,bool>(key, true));

		// behind
		if((iJ - 1) >= 0) {
			if (gameBoard[iI][iJ-1] != '0')
				;// vira
			else
				zeroTurn(iI, iJ-1);
		}
		// front
		if ((iJ + 1) < M) {
			if (gameBoard[iI][iJ+1] != '0')
			 ;// vira
			else
				zeroTurn(iI, iJ + 1);
		}
		// up
		if ((iI - 1) >= 0) {
		       if (gameBoard[iI-1][iJ] != '0')
				; // vira
		       else
			       zeroTurn(iI - 1, iJ);
		}
		// up behiInd
		if (((iI - 1) >= 0 && ((iJ - 1) >= 0))) {
			if (gameBoard[iI-1][iJ-1] !=  '0')
				; // vira
			else
				zeroTurn(iI - 1, iJ - 1);
		}
		// up front
		if ((iI - 1) >= 0 && ((iJ+1) < M)) {
			if (gameBoard[iI-1][iJ+1] != '0')
				; // vira
			else
				zeroTurn(iI - 1, iJ + 1);
		}
		// down
		if ((iI + 1) < N) {
			if (gameBoard[iI+1][iJ] != '0')
				; // vira
			else
				zeroTurn(iI + 1, iJ);
		}
		// down behiInd
		if ((iI + 1 < N) && (iJ - 1 >= 0)) {
			if (gameBoard[iI+1][iJ-1] != '0')
				; // vira
			else
				zeroTurn(iI + 1, iJ - 1);
		}
		// down front
		if (((iI + 1) < N) && (iJ + 1) < M) {
			if (gameBoard[iI+1][iJ+1] != '0')
				; //vira
			else
				zeroTurn(iI + 1, iJ + 1);
		}
	}
}

void MineField::menuGame(void)
{
;
}
