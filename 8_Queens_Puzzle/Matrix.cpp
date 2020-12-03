#include <iostream>
#include "Matrix.h"


int Matrix::getMatrix(int row, int col) {
	return this->matrix[row * this->cols + col];
}

void Matrix::setMatrix(int row, int col, int value) {
	this->matrix[row * this->cols + col] = value;
}

void Matrix::print() {
	
	for (size_t row = 0; row < rows; row++)
	{
		for (size_t col = 0; col < cols; col++)
		{
			std::cout << matrix[row * this->cols + col] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

