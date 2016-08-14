#pragma once

namespace Move {
	typedef double ValueType;
	class Array
	{

	protected:
		friend Array operator+(Array lhs, const Array& rhs);
		friend Array operator+(Array lhs, const ValueType rhs);
		friend Array operator+(const ValueType lhs, Array rhs);
		friend Array operator*(Array lhs, const Array& rhs);


	public:

		// constructor
		Array(int length);
		Array(ValueType* data, int length);

		// constructor (copy)
		Array(const Array & o);

		// constructor (move)
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
