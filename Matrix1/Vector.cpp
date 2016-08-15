#include <iostream>
#include "Vector.h"
#include <cassert>

using namespace std;

namespace Move {

	Vector operator+(Vector lhs, const Vector& rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.data[i] += rhs.data[i];
		}
		return lhs;
	}

	Vector operator+(Vector lhs, const ValueType rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.data[i] += rhs;
		}
		return lhs;
	}

	Vector operator+(const ValueType lhs, Vector rhs) {
		for (int i = 0; i < rhs.length; i++) {
			rhs.data[i] += lhs;
		}
		return rhs;
	}

	Vector operator-(Vector lhs, const Vector& rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.data[i] -= rhs.data[i];
		}
		return lhs;
	}

	Vector operator-(Vector lhs, const ValueType rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.data[i] -= rhs;
		}
		return lhs;
	}

	Vector operator-(const ValueType lhs, Vector rhs) {
		for (int i = 0; i < rhs.length; i++) {
			rhs.data[i] -= lhs;
		}
		return rhs;
	}

	Vector operator*(Vector lhs, const Vector& rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.data[i] *= rhs.data[i];
		}
		return lhs;
	}

	Vector operator*(Vector lhs, const ValueType rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.data[i] *= rhs;
		}
		return lhs;
	}

	Vector operator*(const ValueType lhs, Vector rhs) {
		for (int i = 0; i < rhs.length; i++) {
			rhs.data[i] *= lhs;
		}
		return rhs;
	}

	Vector operator/(Vector lhs, const Vector& rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.data[i] /= rhs.data[i];
		}
		return lhs;
	}

	Vector operator/(Vector lhs, const ValueType rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.data[i] /= rhs;
		}
		return lhs;
	}

	Vector operator/(const ValueType lhs, Vector rhs) {
		for (int i = 0; i < rhs.length; i++) {
			rhs.data[i] /= lhs;
		}
		return rhs;
	}

	// -----

	Vector::Vector(int length, bool isRowVector) {
		assert(length > 0);
		this->length = length;
		this->isRow = isRowVector;
		this->data = new ValueType[length];
		memset(data, 0, sizeof(ValueType) * length);
		cout << "generated(" << this << ")" << endl;
	}

	Vector::Vector(ValueType* data, int length, bool isRowVector) {
		assert(length > 0);
		this->length = length;
		this->isRow = isRowVector;
		this->data = new ValueType[length];
		memcpy(data, data, length * sizeof(ValueType));
		cout << "generated(" << this << ")" << endl;
	}

	Vector::Vector(const Vector& o) {
		this->length = o.length;
		this->isRow = o.isRow;
		this->data = new ValueType[o.length];
		memcpy(data, o.data, sizeof(ValueType) * this->length);
		cout << "copied(" << this << ")" << " <- " << &o << endl;
	}

	Vector::Vector(Vector&& o) {
		this->length = o.length;
		this->isRow = o.isRow;
		this->data = o.data;
		o.data = nullptr;
		o.length = 0;
		cout << "moved(" << this << ")" << " <- " << &o << endl;
	}

	Vector::~Vector() {
		if (data != nullptr) {
			delete data, data = nullptr;
			length = 0;
		}
		cout << "deleted(" << this << ")" << endl;
	}

	Vector& Vector::operator = (Vector& o) {
		assert(o.length > 0);
		this->length = o.length;
		this->isRow = o.isRow;
		memcpy(data, o.data, sizeof(ValueType) * length);
		cout << "copied by '=' (" << this << ")" << " <- " << &o << endl;
		return (*this);
	}

	Vector& Vector::operator = (Vector&& o) {
		if (this != &o) {
			this->length = o.length;
			this->isRow = o.isRow;
			this->data = o.data;
			o.data = nullptr;
			o.length = 0;
			cout << "moved by '=' operator (" << this << ")" << " <- " << &o << endl;
		}
		return (*this);
	}

	// -----

	void Vector::print() {
		assert(this->length > 0);
		for (int i = 0; i < this->length - 1; i++) {
			std::cout << this->data[i] << ", ";
		}
		std::cout << this->data[length - 1] << endl;
	}
}
