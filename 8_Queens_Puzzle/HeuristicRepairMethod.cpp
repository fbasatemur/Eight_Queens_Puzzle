#pragma once
#include "Chessboard.h"

#define BOARDROWS 8
#define BOARDCOLS 8
#define QUEEN 9


int heuristicRepairMethod(Chessboard* board, int step) {

	int row = step / BOARDROWS;
	int col = step % BOARDCOLS;
	int minValue = 8;
	int minRow = 0;

	int intersectionRow = 0;
	int intersectionCol = 0;

	if (board->getMatrix(row, col) == QUEEN) {

		board->setQueenLocation(row, col);

		if (board->isIntersection(row, col)) {

			intersectionCol = board->getIntersectionCol();
			intersectionRow = board->getIntersectionRow();
			board->setQueenLocation(intersectionRow, intersectionCol);

			for (size_t currentRow = 0; currentRow < BOARDROWS; currentRow++) {

				if (board->isIntersection(currentRow, intersectionCol) && currentRow != intersectionRow)
					board->setMatrix(currentRow, intersectionCol, board->getIntersectionCounter());
			}

			board->print();

			for (size_t currentRow = 0; currentRow < BOARDROWS; currentRow++) {

				if (minValue > board->getMatrix(currentRow, intersectionCol)) {
					minRow = currentRow;
					minValue = board->getMatrix(currentRow, intersectionCol);
				}
			}

			for (size_t currentRow = 0; currentRow < BOARDROWS; currentRow++) {

				if (currentRow == minRow)
					board->setMatrix(currentRow, intersectionCol, QUEEN);

				else
					board->setMatrix(currentRow, intersectionCol, 0);
			}

			board->print();

			if (minValue == 0)
				return 0;


			row = minRow;
			col = intersectionCol;

			step = row * BOARDCOLS + col - 1;
		}
	}

	heuristicRepairMethod(board, ++step);
}