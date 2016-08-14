#include <iostream>
#include "Vector.h"

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


	Vector::Vector(int length) {
		this->data = new ValueType[length];
		this->length = length;
		memset(data, 0, sizeof(ValueType) * length);
		cout << "generated(" << this << ")" << endl;
	}

	Vector::Vector(ValueType* data, int length) {
		this->data = new ValueType[length];
		this->length = length;
		memcpy(data, data, length * sizeof(ValueType));
		cout << "generated(" << this << ")" << endl;
	}

	Vector::Vector(const Vector & o) {
		this->data = new ValueType[o.length];
		this->length = o.length;
		memcpy(data, o.data, sizeof(ValueType) * this->length);
		cout << "copied(" << this << ")" << " <- " << &o << endl;
	}

	Vector::Vector(Vector && o) {
		this->data = o.data;
		this->length = o.length;
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

	Vector& Vector::operator = (Vector & o) {
		this->length = o.length;
		memcpy(data, o.data, sizeof(ValueType) * length);
		cout << "copied by '=' (" << this << ")" << " <- " << &o << endl;
		return (*this);
	}

	Vector& Vector::operator = (Vector && o) {
		if (this != &o) {
			this->data = o.data;
			this->length = o.length;
			o.data = nullptr;
			o.length = 0;
			cout << "moved by '=' operator (" << this << ")" << " <- " << &o << endl;
		}
		return (*this);
	}

	void Vector::print() {
		for (int i = 0; i < this->length - 1; i++) {
			std::cout << this->data[i] << ", ";
		}
		std::cout << this->data[length - 1] << endl;
	}
}
