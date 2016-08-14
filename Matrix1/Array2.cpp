#include <iostream>
#include <string.h>
#include "Array2.h"

using namespace std;


namespace Move {

	Array operator+(Array lhs, const Array& rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.p[i] += rhs.p[i];
		}
		return lhs;
	}

	Array operator+(Array lhs, const ValueType rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.p[i] += rhs;
		}
		return lhs;
	}

	Array operator+(const ValueType lhs, Array rhs) {
		for (int i = 0; i < rhs.length; i++) {
			rhs.p[i] += lhs;
		}
		return rhs;
	}

	Array operator*(Array lhs, const Array& rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.p[i] *= rhs.p[i];
		}
		return lhs;
	}


	Array::Array(int length)
		: p(new ValueType[length])
		, length(length)
	{
		memset(p, 0, sizeof(ValueType) * length);
		p[0] = 123;

		cout << "generated(" << this << ")" << endl;
	}

	Array::Array(ValueType* data, int length)
		: p(new ValueType[length])
		, length(length)
	{
		memcpy(p, data, length * sizeof(ValueType));
		cout << "generated(" << this << ")" << endl;
	}

	Array::Array(const Array & o)
		: p(new ValueType[o.length])
		, length(o.length)
	{
		memcpy(p, o.p, sizeof(ValueType) * length);
		cout << "copied(" << this << ")" << " <- " << &o << endl;
	}

	Array::Array(Array && o)
		: p(o.p)
		, length(o.length)
	{
		o.p = nullptr;
		o.length = 0;

		cout << "moved(" << this << ")" << " <- " << &o << endl;
	}

	Array::~Array() {
		if (p != nullptr) {
			delete p, p = nullptr;
			length = 0;
		}
		cout << "deleted(" << this << ")" << endl;
	}

	Array & Array::operator = (Array & o)
	{
		length = o.length;
		memcpy(p, o.p, sizeof(ValueType) * length);
		cout << "copied by '=' (" << this << ")" << " <- " << &o << endl;
		return (*this);
	}

	Array & Array::operator = (Array && o)
	{
		if (this != &o) {
			p = o.p;
			length = o.length;

			o.p = nullptr;
			o.length = 0;

			cout << "moved by '=' operator (" << this << ")" << " <- " << &o << endl;
		}
		return (*this);
	}

	void Array::print() {
		for (int i = 0; i < this->length - 1; i++) {
			std::cout << this->p[i] << ", ";
		}
		std::cout << this->p[length - 1] << endl;
	}
}
