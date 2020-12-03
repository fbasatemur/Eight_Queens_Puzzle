#pragma once

class Matrix {

protected:
	int cols;
	int rows;
	int* matrix;
	int queen = 9;

public:
	int getMatrix(int row, int col);
	void setMatrix(int row, int col, int value);
	void print();
};