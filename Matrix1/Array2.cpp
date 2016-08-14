#include <iostream>
#include <string.h>
#include "Array2.h"

using namespace std;


namespace Move {

	Array operator+(Array lhs, const Array& rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.p[i] += rhs.p[i];
		}
		return lhs; // return the result by value (uses move constructor)
	}

	Array operator+(Array lhs, const ValueType rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.p[i] += rhs;
		}
		return lhs; // return the result by value (uses move constructor)
	}

	Array operator+(const ValueType lhs, Array rhs) {
		for (int i = 0; i < rhs.length; i++) {
			rhs.p[i] += lhs;
		}
		return rhs; // return the result by value (uses move constructor)
	}

	Array operator*(Array lhs, const Array& rhs) {
		for (int i = 0; i < lhs.length; i++) {
			lhs.p[i] *= rhs.p[i];
		}

		return lhs; // return the result by value (uses move constructor)
	}


	// コンストラクタ
	Array::Array(int _length)
		: p(new ValueType[_length])
		, length(_length)
	{
		memset(p, 0, sizeof(ValueType) * length);
		p[0] = 123;

		cout << "constructor(" << this << ")" << endl;
	}

	Array::Array(ValueType* data, int length)
		: p(new ValueType[length])
		, length(length)
	{
		memcpy(p, data, length * sizeof(ValueType));
		cout << "constructor(" << this << ")" << endl;
	}


	// コピーコンストラクタ
	Array::Array(const Array & o)
		: p(new ValueType[o.length])
		, length(o.length)
	{
		memcpy(p, o.p, sizeof(ValueType) * length);
		cout << "copy constructor(" << this << ")" << " <- " << &o << endl;
	}

	// ムーブコンストラクタ
	Array::Array(Array && o)
		: p(o.p)
		, length(o.length)
	{
		o.p = nullptr;
		o.length = 0;

		cout << "move constructor(" << this << ")" << " <- " << &o << endl;
	}

	// デストラクタ
	Array::~Array() {
		if (p != nullptr) {
			delete p, p = nullptr;
			length = 0;
		}
		cout << "destructor(" << this << ")" << endl;
	}

	// 代入演算子(コピー)
	Array & Array::operator = (Array & o)
	{
		length = o.length;
		memcpy(p, o.p, sizeof(ValueType) * length);
		cout << "copy(" << this << ")" << " <- " << &o << endl;
		return (*this);
	}

	// 代入演算子(ムーブ)
	Array & Array::operator = (Array && o)
	{
		if (this != &o) {
			p = o.p;
			length = o.length;

			o.p = nullptr;
			o.length = 0;

			cout << "move(" << this << ")" << " <- " << &o << endl;
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
