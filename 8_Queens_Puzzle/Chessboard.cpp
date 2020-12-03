#include "Chessboard.h"

Chessboard::Chessboard(int rows, int cols) {

	this->rows = rows;
	this->cols = cols;
	matrix = new int[rows * cols]{ 0, 0, 0, 0, 0, 9, 0, 0,
								   0, 9, 0, 0, 0, 0, 0, 0,
								   0, 0, 0, 0, 9, 0, 0, 0,
								   9, 0, 0, 0, 0, 0, 0, 0,
								   0, 0, 0, 9, 0, 0, 0, 0,
								   0, 0, 0, 0, 0, 0, 9, 0,
								   0, 0, 9, 0, 0, 0, 0, 0,
								   0, 0, 0, 0, 0, 0, 0, 9 };
}

void Chessboard::colIntersection(int currentRow, int currentCol) {
	
	for (int row = 0; row < this->rows; row++)
	{
		if (this->getMatrix(row, currentCol) == queen && row != this->queenRow) {
			intersectionCounter++;
			intersectionRow = row;
			intersectionCol = currentCol;
		}
	}
}

void Chessboard::rowIntersection(int currentRow, int currentCol) {

	for (int col = 0; col < this->cols; col++)
	{
		if (this->getMatrix(currentRow, col) == queen && col != this->queenCol) {
			intersectionCounter++;
			intersectionRow = currentRow;
			intersectionCol = col;
		}
	}
}

void Chessboard::crossIntersection(int currentRow, int currentCol) {

	// Right Cross Intersection
	for (int row = currentRow + 1, col = currentCol + 1; row < rows && col < cols; row++, col++)
	{
		if (this->getMatrix(row, col) == queen) {
			intersectionCounter++;
			intersectionRow = row;
			intersectionCol = col;
		}
	}

	for (int row = currentRow - 1, col = currentCol - 1; row >= 0 && col >= 0; row--, col--)
	{
		if (this->getMatrix(row, col) == queen) {
			intersectionCounter++;
			intersectionRow = row;
			intersectionCol = col;
		}
	}

	// Left Cross Intersection
	for (int row = currentRow - 1, col = currentCol + 1; row >= 0 && col < cols; row--, col++)
	{
		if (this->getMatrix(row, col) == queen) {
			intersectionCounter++;
			intersectionRow = row;
			intersectionCol = col;
		}
	}

	for (int row = currentRow + 1, col = currentCol - 1; row < rows && col >= 0; row++, col--)
	{
		if (this->getMatrix(row, col) == queen) {
			intersectionCounter++;
			intersectionRow = row;
			intersectionCol = col;
		}
	}
}

bool Chessboard::isIntersection(int currentRow, int currentCol) {
	
	resetCounter();

	rowIntersection(currentRow, currentCol);
	colIntersection(currentRow, currentCol);
	crossIntersection(currentRow, currentCol);
	
	if (intersectionCounter != 0) 
		return true;
	
	return false;
}

int Chessboard::getIntersectionCounter() {
	return this->intersectionCounter;
}

void Chessboard::resetCounter() {
	this->intersectionCounter = 0;
}

void Chessboard::setQueenLocation(int queenRow, int queenCol)
{
	this->queenRow = queenRow;
	this->queenCol = queenCol;
}

int Chessboard::getIntersectionRow() {
	return this->intersectionRow;
}

int Chessboard::getIntersectionCol() {
	return this->intersectionCol;
}

Chessboard::~Chessboard() {
	delete[] matrix;
}