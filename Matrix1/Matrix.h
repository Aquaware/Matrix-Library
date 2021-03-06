#pragma once
#include "Vector.h"

namespace Move {
	class Matrix {

	public:
		// constructor
		Matrix(int rows, int cols);
		Matrix(ValueType* data, int rows, int cols);

		// constructor (copy)
		Matrix(const Matrix& o);

		// constructor (move)
		Matrix(Matrix && o);

		// destructor
		~Matrix();

		// assigment operation (copy)
		Matrix& operator = (Matrix& o);

		//  assigment operation (move)
		Matrix& operator = (Matrix&& o);

	protected:
		// operators oveload
		friend Matrix operator+(Matrix lhs, const Matrix& rhs);
		friend Matrix operator+(Matrix lhs, const ValueType rhs);
		friend Matrix operator+(const ValueType lhs, Matrix rhs);
		friend Matrix operator-(Matrix lhs, const Matrix& rhs);
		friend Matrix operator-(Matrix lhs, const ValueType rhs);
		friend Matrix operator-(const ValueType lhs, Matrix rhs);
		friend Matrix operator*(Matrix lhs, const Matrix& rhs);
		friend Matrix operator*(Matrix lhs, const ValueType rhs);
		friend Matrix operator*(const ValueType lhs, Matrix rhs);
		friend Matrix operator/(Matrix lhs, const Matrix& rhs);
		friend Matrix operator/(Matrix lhs, const ValueType rhs);
		friend Matrix operator/(const ValueType lhs, Matrix rhs);

	public:
		int size() { return this->length; };
		int colSize() { return this->cols; };
		int rowSize() { return this->rows; };
		ValueType* array() { return this->data; };
		ValueType** arrays() { return this->vectors; };
		Matrix product(const Matrix& rhs);

		void print();

	private:
		int cols;
		int rows;
		int length;
		ValueType* data;
		ValueType** vectors;

		void create();
		void createVectors();
		void deleteDataAndVectors();
	};
}
