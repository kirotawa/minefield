#include "include/mine.h"

int main(void) {
	MineField m;


	m.initGame(MINES);
	m.printBoard();

	return 0;
}
