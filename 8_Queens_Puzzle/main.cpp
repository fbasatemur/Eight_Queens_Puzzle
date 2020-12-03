#include <stdlib.h>

#include "Chessboard.h"
#include "HeuristicRepairMethod.cpp"

#define BOARDROWS 8
#define BOARDCOLS 8


void main() {

	Chessboard board(BOARDROWS, BOARDCOLS);

	heuristicRepairMethod(&board, 0);

	system("pause");
}