#pragma once
#include "Matrix.h"

class Chessboard: public Matrix{
	
private:
	int intersectionCounter = 0;
	int queenRow = 0;
	int queenCol = 0;
	int intersectionRow = 0;
	int intersectionCol = 0;


public:
	Chessboard(int rows, int cols);
	void setQueenLocation(int queenRow, int queenCol);
	int getIntersectionRow();
	int getIntersectionCol();

	void rowIntersection(int currentRow, int currentCol);
	void colIntersection(int currentRow, int currentCol);
	void crossIntersection(int currentRow, int currentCol);

	bool isIntersection(int currentRow, int currentCol);
	int getIntersectionCounter();
	void resetCounter();
	~Chessboard();

};