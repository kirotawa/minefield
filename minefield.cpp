#include "include/mine.h"

int main(void) {
	MineField m;


	m.initGame(MINES);
	m.menuGame();
	//m.printBoard();

	return 0;
}
