#pragma once

namespace Move {
	typedef double ValueType;
	class Vector {

	public:
		// constructor
		Vector(int length, bool isRowVector = true);
		Vector(ValueType* data, int length, bool isRowVector = true);

		// constructor (copy)
		Vector(const Vector& o);

		// constructor (move)
		Vector(Vector && o);

		// destructor
		~Vector();

		// assigment operation (copy)
		Vector& operator = (Vector& o);

		//  assigment operation (move)
		Vector& operator = (Vector&& o);

	protected:
		// operators oveload
		friend Vector operator+(Vector lhs, const Vector& rhs);
		friend Vector operator+(Vector lhs, const ValueType rhs);
		friend Vector operator+(const ValueType lhs, Vector rhs);
		friend Vector operator-(Vector lhs, const Vector& rhs);
		friend Vector operator-(Vector lhs, const ValueType rhs);
		friend Vector operator-(const ValueType lhs, Vector rhs);
		friend Vector operator*(Vector lhs, const Vector& rhs);
		friend Vector operator*(Vector lhs, const ValueType rhs);
		friend Vector operator*(const ValueType lhs, Vector rhs);
		friend Vector operator/(Vector lhs, const Vector& rhs);
		friend Vector operator/(Vector lhs, const ValueType rhs);
		friend Vector operator/(const ValueType lhs, Vector rhs);

	public:
		int size() { return this->length; };
		ValueType* array() { return this->data; };

		void print();

	private:
		int length;
		bool isRow;
		ValueType *data;
	};
}
