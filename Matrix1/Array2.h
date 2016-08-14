#pragma once

namespace Move {
	typedef double ValueType;
	class Array
	{

	public:
		friend Array operator+(Array lhs, const Array& rhs);
		friend Array operator+(Array lhs, const ValueType rhs);
		friend Array operator+(const ValueType rhs, Array lhs);
		friend Array operator*(Array lhs, const Array& rhs);

		// constructor
		Array(int _length);
		Array(ValueType* data, int length);

		// copy constructor
		Array(const Array & o);

		// move constructor
		Array(Array && o);

		// destructor
		~Array();

		// assigment operation (copy)
		Array & operator = (Array & o);


		//  assigment operation (move)
		Array & operator = (Array && o);

	public:
		void print();


	private:
		ValueType *p;
		int length;
	};
}
