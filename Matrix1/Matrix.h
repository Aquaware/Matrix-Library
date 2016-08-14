#pragma once
#include <memory>

class Matrix
{
public:
	Matrix();
	Matrix(const int rows, const int cols);
	Matrix(const double* data, const int rows, const int cols);
	Matrix& operator=(const Matrix& other);
	Matrix& operator=(Matrix&& other);

	// friends defined inside class body are inline and are hidden from non-ADL lookup
//	friend Matrix operator+(Matrix lhs,        // passing lhs by value helps optimize chained a+b+c
//		const Matrix& rhs) // otherwise, both parameters may be const references
//	{
//		lhs += rhs; // reuse compound assignment
//		for (int i = 0; i < lhs.rows * lhs.cols; i++) {
//			lhs.array[i] = rhs.array[i];
//		}


//		return lhs; // return the result by value (uses move constructor)
//	}

///
//	Matrix& operator+=(const Matrix& rhs) // compound assignment (does not need to be a member,
//	{                           // but often is, to modify the private members)
								// addition of rhs to *this takes place here 


//		return *this; // return the result by reference
//	}



		~Matrix();




	int cols;
	int rows;
	double* array;


};

