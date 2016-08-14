#include "Matrix.h"
#include <cassert>



Matrix::Matrix()
{
}

Matrix::Matrix(const int rows, const int cols) {
	this->rows = rows;
	this->cols = cols;
	this->array = new double[rows * cols];
}

Matrix::Matrix(const double* data, const int rows, const int cols) {
	this->rows = rows;
	this->cols = cols;
	this->array = new double[rows * cols];
	for (int i = 0; i < rows * cols; i++) {
		array[i] = data[i];
	}
}

Matrix& Matrix:: operator=(const Matrix& other) // copy assignment
{
	if (this != &other) { // self-assignment check expected
		if (true) {
			/* storage cannot be reused (e.g. different sizes) */
		
			delete[] array;            // destroy storage in this
										/* reset size to zero and mArray to null, in case allocation throws */
			array = new double[this->rows * this->cols]; // create storage in this
		}
		/* copy data from other's storage to this storage */
		for (int i = 0; i < rows * cols; i++) {
			this->array[i] = other.array[i];
		}
	}
	return *this;
}
Matrix& Matrix:: operator=(Matrix&& other) // move assignment
{
	assert(this != &other); // self-assignment check not required
	delete[] array;        // delete this storage
	array = std::exchange(other.array, nullptr); // leave moved-from in valid state
	return *this;
}

Matrix::~Matrix()
{
	delete[] array;
}
