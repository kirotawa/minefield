#include <map>

#define N 50
#define M 50
#define PERCENT 15
#define MINES ((M*N)*PERCENT)/100

class MineField
{
	// defines the board game. By now, the dimensions is fixed/harded coded
	char gameBoard[N][M];
	char _printBoard[N][M];
	char flagBoard[N][M];
	bool flapped[N][M];
	bool isOver = false;
	bool isKaboom = false;
	std::map<std::string, bool> visitedMap;
private:
	// checks if a postion is a valid one:
	bool checkPosition(int pos1, int pos2);
	bool checkPositionGameBoard(int pos1, int pos2);
	void initGameBoard(int mines);
	void updatePrintBoard(void);
	void numbersBoard(void);
	void uncoveringBoard(void);
	void zeroTurn(int i, int j);
	void turnPos(int i, int j);
public:
	void updateBoard(int pos1, int pos2);
	void printBoard(void);
	void initGame(int mines);
	void menuGame(void);
};
