#include <iostream>
#include <cassert>
#include "Matrix.h"

using namespace std;

namespace Move {

	Matrix operator+(Matrix lhs, const Matrix& rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.data[i] += rhs.data[i];
		}
		return lhs;
	}

	Matrix operator+(Matrix lhs, const ValueType rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.data[i] += rhs;
		}
		return lhs;
	}

	Matrix operator+(const ValueType lhs, Matrix rhs) {
		for (int i = 0; i < rhs.length; i++) {
			rhs.data[i] += lhs;
		}
		return rhs;
	}

	Matrix operator-(Matrix lhs, const Matrix& rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.data[i] -= rhs.data[i];
		}
		return lhs;
	}

	Matrix operator-(Matrix lhs, const ValueType rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.data[i] -= rhs;
		}
		return lhs;
	}

	Matrix operator-(const ValueType lhs, Matrix rhs) {
		for (int i = 0; i < rhs.length; i++) {
			rhs.data[i] -= lhs;
		}
		return rhs;
	}

	Matrix operator*(Matrix lhs, const Matrix& rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.data[i] *= rhs.data[i];
		}
		return lhs;
	}

	Matrix operator*(Matrix lhs, const ValueType rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.data[i] *= rhs;
		}
		return lhs;
	}

	Matrix operator*(const ValueType lhs, Matrix rhs) {
		for (int i = 0; i < rhs.length; i++) {
			rhs.data[i] *= lhs;
		}
		return rhs;
	}

	Matrix operator/(Matrix lhs, const Matrix& rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.data[i] /= rhs.data[i];
		}
		return lhs;
	}

	Matrix operator/(Matrix lhs, const ValueType rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.data[i] /= rhs;
		}
		return lhs;
	}

	Matrix operator/(const ValueType lhs, Matrix rhs) {
		for (int i = 0; i < rhs.length; i++) {
			rhs.data[i] /= lhs;
		}
		return rhs;
	}

	// -----

	Matrix::Matrix(int rows, int cols) {
		assert(rows > 0 && cols > 0);
		this->rows = rows;
		this->cols = cols;
		create();
		memset(data, 0, sizeof(ValueType) * this->length);
		cout << "generated(" << this << ")" << endl;
	}

	Matrix::Matrix(ValueType* data, int rows, int cols) {
		assert(rows > 0 && cols > 0);
		this->rows = rows;
		this->cols = cols;
		create();
		memcpy(data, data, length * sizeof(ValueType));
		cout << "generated(" << this << ")" << endl;
	}

	// constructor (copy)
	Matrix::Matrix(const Matrix& o) {
		this->rows = o.rows;
		this->cols = o.cols;
		create();
		memcpy(data, o.data, sizeof(ValueType) * this->length);
		cout << "copied(" << this << ")" << " <- " << &o << endl;
	}

	// constructor (move)
	Matrix::Matrix(Matrix&& o) {
		this->rows = o.rows;
		this->cols = o.cols;
		this->length = o.length;
		this->data = o.data;
		o.data = nullptr;
		o.length = 0;
		this->vectors = o.vectors;
		o.vectors = nullptr;
		cout << "moved(" << this << ")" << " <- " << &o << endl;
	}

	Matrix::~Matrix() {
		if (this->data != nullptr) {
			deleteDataAndVectors();
		}
		cout << "deleted(" << this << ")" << endl;
	}

	// assigment operation (copy)
	Matrix& Matrix::operator = (Matrix& o) {
		this->rows = o.rows;
		this->cols = o.cols;
		this->length = o.length;
		memcpy(this->data, o.data, sizeof(ValueType) * this->length);
		delete this->vectors;
		createVectors();
		cout << "copied by '=' (" << this << ")" << " <- " << &o << endl;
		return (*this);
	}

	//  assigment operation (move)
	Matrix& Matrix::operator = (Matrix&& o) {
		if (this != &o) {
			this->rows = o.rows;
			this->cols = o.cols;
			this->length = o.length;
			this->data = o.data;
			o.data = nullptr;
			o.length = 0;
			this->vectors = o.vectors;
			o.vectors = nullptr;
			cout << "moved by '=' operator (" << this << ")" << " <- " << &o << endl;
		}
		return (*this);
	}

	Matrix Matrix::product(const Matrix& rhs) {
		Matrix out(this->rows, rhs.cols);
		for (int r = 0; r < this->rows; r++) {
			for (int c = 0; c < this->cols; c++) {
				ValueType sum = 0.0;
				for (int k = 0; k < this->cols; k++) {
					sum += this->vectors[r][k] * rhs.vectors[k] [c];
				}
				out.vectors[r][c] = sum;
			}
		}
		return out;
	}

	void Matrix::deleteDataAndVectors() {
		delete this->vectors;
		this->vectors = nullptr;
		delete this->data;
		this->data = nullptr;
		this->rows = 0;
		this->cols = 0;
		this->length = 0;
	}

	void Matrix::create() {
		this->length = this->rows * this->cols;
		this->data = new ValueType[this->length];
		createVectors();
	}

	void Matrix::createVectors() {
		this->vectors = new ValueType*[this->rows];
		ValueType* p = this->data;
		for (int i = 0; i < this->rows; i++) {
			this->vectors[i] = p;
			p += this->cols;
		}
	}

	// -----

	void Matrix::print() {
		for (int r = 0; r < this->rows; r++) {
			for (int c = 0; c < this->cols - 1; c++) {
				std::cout << this->vectors[r][c] << ", ";
			}
			std::cout << this->vectors[r][this->cols - 1]  << endl;
		}
	}
}
